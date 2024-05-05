import random
import numpy as np
import matplotlib.pyplot as plt


#
# Value Generator
#
def generate_data_array_with_errors(max, min, len, stdev):
    data = list()
    data = [random.uniform(min, max) for _ in range(len)]
    data.sort()
    data_noise = data.copy()
    for i in range(len):
        noise = np.random.normal(0, stdev)
        data_noise[i] += noise + np.sin(0.2 * data[i]) + 0.5 * np.cos(1 * data[i]) + 0.001 * i

    return data, data_noise


def rmse(gt: list, measured: list) -> float:
    gt = np.array(gt)
    measured = np.array(measured)
    squared_error = np.square(gt - measured)
    return np.mean(squared_error)

#
# Polynomial Regression
#


def create_design_matrix(degree, x):
    columns = []

    for d in range(degree + 1):
        columns.append(np.power(x, d))

    X = np.column_stack(columns)
    return X


def polynomial_regression(order, data, noise):
    X = create_design_matrix(order, noise)
    Y = np.array(data)
    return (np.linalg.inv(X.T @ X) @ X.T @ Y)[::-1]

#
# Linear Interpolation
#


'''
generate_correcton_data_linear_interpolation(data, noise) generates a
dictornary filled with data that is ment to be added to a measurement to correct
it.
linera_interpolation(measurement, correction_data) finds the nearest two values
from the correction_data dict and linearly interpolates them returning the
estimated value
'''


def generate_correcton_data_linear_interpolation(data: list, noise: list) -> list:
    correction_data = list()
    for i in range(len(data)):
        correction_data.append(data[i] - noise[i])
    return correction_data


def linear_interpolation(x: float, noise: list, correction_data: list, gt_data):
    largest_left = [0, -100]
    largest_right = [0, 100]
    for i, val in enumerate(noise):
        if (val > largest_left[1] and val <= x):
            largest_left = [i, val]
        if (val < largest_right[1] and val >= x):
            largest_right = [i, val]

    d = abs(largest_left[1] - largest_right[1])
    val_left = correction_data[largest_left[0]] * (1 - abs(largest_left[1] - x) / d)
    val_right = correction_data[largest_right[0]] *  (1 - abs(x - largest_right[1]) / d)
    corrected_value = x + val_right + val_left
    return corrected_value

#
# B-Spline Interpolation
#
def b_spline_interpolation(data: list, noise: list) -> list:

#
# Test Code
#


order = 7
data_pre, noise_pre = generate_data_array_with_errors(55, -55, 11000, 0.1)
data = data_pre[::2]
data_test_values = data_pre[1::2]
noise = noise_pre[::2]
noise_test_values = noise_pre[1::2]

weights = polynomial_regression(order, data, noise)
polynomial = np.poly1d(weights)

correction_data = generate_correcton_data_linear_interpolation(data, noise)


x_values = np.linspace(-55, 55, 1000)
y_pol = polynomial(x_values)
y_values = polynomial(noise)

print("error of polynomial regression: ", rmse(data, y_values))

linear_corrected = list()
for i in range(len(noise_test_values)):
    linear_corrected.append(linear_interpolation(noise_test_values[i], noise, correction_data, data_test_values[i]))

print("error of linear interpolation: ", rmse(data, linear_corrected))

plt.plot(data, y_values, label='corrected data')
plt.plot(x_values, y_pol, label='polynomial')
plt.plot(x_values, x_values, label='ideal data')
plt.plot(data, linear_corrected, label='linear corrected')
plt.scatter(data, noise, label='data')
plt.legend()
plt.show()
