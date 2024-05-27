#ifndef __MATRIX
#define __MATRIX
#include "math.h"
#include <vector>
#include <cstdlib>
#include <stdexcept>

class Vector_3D;
template <typename T>
class Vector;


class Matrix_3D {
    public: 
        double r[3][3];

    public: 
        Matrix_3D();

        Matrix_3D inverse() const;
        double determinant() const;
        Matrix_3D I() const;
        void print() const;

        Vector_3D operator*(Vector_3D v) const;
        Matrix_3D& operator=(const Matrix_3D& other);
        Matrix_3D operator*(const Matrix_3D& other) const;
        Matrix_3D operator*(const double scalar) const;
        Matrix_3D operator+(const Matrix_3D& other) const;
};

template <typename T>
class Matrix {
public:
    std::vector<std::vector<T>> data;
    int rows;
    int cols;

public:
    Matrix();
    Matrix(int n, int m);

    static Matrix<T> Identity(int size);
    std::vector<T> operator*(const std::vector<T>& vec) const;
    Vector<T> operator*(const Vector<T>& vec) const;
    Matrix<T>& operator=(const Matrix<T>& other);
    Matrix<T> operator*(const Matrix<T>& other) const;
    Matrix<T> operator*(const T scalar) const;
    Matrix<T> operator+(const Matrix<T>& other) const;

    void print() const;

    Matrix<T> submatrix(int excludeRow, int excludeCol) const;
    T determinant() const;
    Matrix<T> adjugate() const;
    Matrix<T> inverse() const;

    Matrix<T> transpose() const;

/*
 * this section implements the more complex linear algebra algorithms
 */
public: 
    /*
     * This Algrithm does QR decomposition using Gram-Schmidt on the Matrix A.
     * if A is 
     */
    void QR_decomp(Matrix<T> &A, Matrix<T> &Q, Matrix<T> &R);

    /*
     * returns the Eigen-Vectors and Eigen-Values using QR-decomposition
     */
    void eigen(Matrix<T> &eigen_vectors, Vector<T> &eigen_values, double tolerance = 1e-6);

    /*
     * Performs singlular value decompostion on itself 
     */
    Matrix<T> singular_value_decomposition(Matrix<T>& U, Matrix<T>& S, Matrix<T>& V) const;

    /*
     * This functio returns the Moore-Penrose Pseudo inverse using Single-Value-Decomposition
     */
    Matrix<T> moore_penrose();

};

template class Matrix<double>;

#endif
