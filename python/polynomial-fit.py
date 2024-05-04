import random
import numpy as np
import matplotlib.pyplot as plt


def generate_data_array_with_errors(max, min, len, stdev):
    data = list()
    data = [random.uniform(min, max) for _ in range(len)]
    data.sort()
    data_noise = data.copy()
    for i in range(len):
        noise = np.random.normal(0, stdev)
        data_noise[i] += noise + np.sin(0.2 * data[i]) + 2 * np.cos(0.1 * data[i])

    return data, data_noise


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


order = 7
data, noise = generate_data_array_with_errors(55, 0, 550, 0.1)

weights = polynomial_regression(order, data, noise)

print(weights)

polynomial = np.poly1d(weights)

x_values = np.linspace(0, 55, 100)
y_pol = polynomial(x_values)
y_values = polynomial(noise)


plt.plot(data, y_values, label='corrected data')
plt.plot(x_values, y_pol, label='polynomial')
plt.plot(x_values, x_values, label='ideal data')
plt.scatter(data, noise, label='data')
plt.legend()
plt.show()
