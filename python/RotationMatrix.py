import numpy as np

def matrix_vector_multi(vector, matrix):
    x = vector[0] * matrix[0][0] + vector[1] * matrix[0][1] + vector[2] * matrix[0][2]
    y = vector[0] * matrix[1][0] + vector[1] * matrix[1][1] + vector[2] * matrix[1][2]
    z = vector[0] * matrix[2][0] + vector[1] * matrix[2][1] + vector[2] * matrix[2][2]
    return [x, y, z]

def calculate_length(vector):
    return np.sqrt(vector[0] * vector[0] + vector[1] * vector[1] + vector[2] * vector[2])


def normalize_vector(vector):
    return  vector / np.linalg.norm(vector)


def dot_product(vect1, vect2):
    return vect1[0] * vect2[0] + vect1[1] * vect2[1] + vect1[2] * vect2[2]


def cross_product(a,b):
    s1 = a[1] * b[2] - a[2] * b[1]
    s2 = a[2] * b[0] - a[0] * b[2]
    s3 = a[0] * b[1] - a[1] * b[0]
    return [s1, s2, s3]


def determine_matrix(vector1, vector2):
    vector1 = normalize_vector(vector1)
    vector2 = normalize_vector(vector2)

    cos = dot_product(vector1, vector2)
    sin = calculate_length(cross_product(vector1, vector2))

    # the rotation matrix in raw form
    rot_raw = [[cos, (-sin), 0], [sin, cos, 0], [0, 0, 1]]

    # <vector1|vector2> vector1 / ||<vector1|vector2> vector1||  = vector1

    vdiff = vector2
    length = dot_product(vector1, vector2)
    vdiff[0] -= length * vector1[0]
    vdiff[1] -= length * vector1[1]
    vdiff[2] -= length * vector1[2]

    u = vector1
    v = normalize_vector(vdiff)
    w = cross_product(vector2,vector1)

    base_change_inverse = [u, v, w]
    base_change = np.linalg.inv(base_change_inverse)
    print(base_change_inverse)
    print(base_change)

    rotation_matrix = np.dot(base_change, np.dot(rot_raw, base_change_inverse))
    return rotation_matrix



v = np.array([0,0,1])
w = np.array([1,0,0])

v = normalize_vector(v)
w = normalize_vector(w)
print(v)

rmat = determine_matrix(v,w)

print(w @ rmat)
