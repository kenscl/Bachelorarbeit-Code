#include "matlib.h"
#include <cstdio>
#include <cstdlib>

Vector_3D::Vector_3D() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector_3D::Vector_3D(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector_3D::Vector_3D(Vector_3D const &other){
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
}

Vector_3D Vector_3D::cross_product(Vector_3D other) const{
    Vector_3D result;
    result.x = this->y * other.z - this->z * other.y;
    result.y = this->z * other.x - this->x * other.z;
    result.z = this->x * other.y - this->y * other.x;
    return result;
}

double Vector_3D::norm() const{
    double norm;
    norm = sqrt(x*x + y*y + z*z);
    return norm;
}
Vector_3D Vector_3D::normalize() const{
    double norm;
    norm = this->norm();
    if (norm == 0) return Vector_3D(0,0,0);

    Vector_3D result;
    result.x = this->x / norm;
    result.y = this->y / norm;
    result.z = this->z / norm;
    
    return result;
}

double Vector_3D::calculate_angle(Vector_3D other) const{
    double ac;
    Vector_3D v1, v2;
    v1 = this->normalize();
    v2 = other.normalize();
    double res;
    res = v1 * v2;
    ac = acos (res);
    return ac;
}

Matrix_3D Vector_3D::rmat_to(Vector_3D target) const{
    Vector_3D v1 = this->normalize();
    Vector_3D v2 = target.normalize();
    if (v1 == v2) {
        Matrix_3D ret;
        return ret.I();
    }
    Vector_3D vdiff = v2;

    double cos = v1 * v2;
    double length = cos;
    double sin = (v1.cross_product(v2)).norm();


    Matrix_3D rot;
    rot.r[0][0] = cos;
    rot.r[0][1] = - sin;
    rot.r[0][2] = 0;

    rot.r[1][0] = sin;
    rot.r[1][1] = cos;
    rot.r[1][2] = 0;

    rot.r[2][0] = 0; 
    rot.r[2][1] = 0; 
    rot.r[2][2] = 1; 

    vdiff.x -= length * v1.x;
    vdiff.y -= length * v1.y;
    vdiff.z -= length * v1.z;

    vdiff = vdiff.normalize();
    Vector_3D w = v2.cross_product(v1);

    Matrix_3D base_change_inv;

    base_change_inv.r[0][0] = v1.x;
    base_change_inv.r[0][1] = v1.y;
    base_change_inv.r[0][2] = v1.z;

    base_change_inv.r[1][0] = vdiff.x;
    base_change_inv.r[1][1] = vdiff.y;
    base_change_inv.r[1][2] = vdiff.z;

    base_change_inv.r[2][0] = w.x;
    base_change_inv.r[2][1] = w.y;
    base_change_inv.r[2][2] = w.z;

    Matrix_3D base_change;
    base_change = base_change_inv.inverse();
    Matrix_3D rmat = base_change * rot * base_change_inv;

    return rmat;

}

double Vector_3D::distance_to(Vector_3D other) const {
    Vector_3D res;
    res = *this - other;
    return res.norm();
}

void Vector_3D::print() const{
    printf("Vector: \n");
    printf("x: %.5f \n", this->x);
    printf("y: %.5f \n", this->y);
    printf("z: %.5f \n", this->z);
}
Vector_3D Vector_3D::operator*(double value) const{
    Vector_3D result;
    result.x = value * this->x;
    result.y = value * this->y;
    result.z = value * this->z;
    return result;
}

Vector_3D Vector_3D::operator/(double value) const{
    Vector_3D result;
    result.x = this->x / value;
    result.y = this->y / value;
    result.z = this->z / value;
    return result;
}

double Vector_3D::operator*(Vector_3D other) const{
    double res;
    res = this->x * other.x + this->y * other.y + this->z * other.z;
    return res;
}

Vector_3D Vector_3D::operator+(Vector_3D other) const{
    Vector_3D result;
    result.x = this->x + other.x;
    result.y = this->y + other.y;
    result.z = this->z + other.z;
    return result;
}

Vector_3D Vector_3D::operator-(Vector_3D other) const{
    Vector_3D result;
    result.x = this->x - other.x;
    result.y = this->y - other.y;
    result.z = this->z - other.z;
    return result;
}

bool Vector_3D::operator==(Vector_3D other) const{
    if (this->x == other.x && this->y == other.y && this->z == other.z) return true;
    return false;
}

Matrix_3D::Matrix_3D(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            this->r[i][j] = 0;
        }
    }
}


Matrix_3D Matrix_3D::I() const{
    Matrix_3D ret;
    ret.r[0][0] = 1;
    ret.r[0][1] = 0;
    ret.r[0][2] = 0;

    ret.r[1][0] = 0;
    ret.r[1][1] = 1;
    ret.r[1][2] = 0;

    ret.r[2][0] = 0;
    ret.r[2][1] = 0;
    ret.r[2][2] = 1;
    return ret;
}
Vector_3D Matrix_3D::operator*(Vector_3D v) const{
    Vector_3D result;
    result.x = this->r[0][0] * v.x + this->r[0][1] * v.y + this->r[0][2] * v.z;
    result.y = this->r[1][0] * v.x + this->r[1][1] * v.y + this->r[1][2] * v.z;
    result.z = this->r[2][0] * v.x + this->r[2][1] * v.y + this->r[2][2] * v.z;
    return result;
}
Matrix_3D& Matrix_3D::operator=(const Matrix_3D& other){
        if (this != &other) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    r[i][j] = other.r[i][j];
                }
            }
        }
        return *this;
}
Matrix_3D Matrix_3D::operator*(const Matrix_3D& other) const{
    Matrix_3D result;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                result.r[i][j] += this->r[i][k] * other.r[k][j];
            }
        }
    }
    return result;
}

Matrix_3D Matrix_3D::operator*(const double scalar) const {
    Matrix_3D result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.r[i][j] = r[i][j] * scalar;
        }
    }
    return result;
}
Matrix_3D Matrix_3D::operator+(const Matrix_3D& other) const {
        Matrix_3D result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.r[i][j] = r[i][j] + other.r[i][j];
            }
        }
        return result;
    }
void Matrix_3D::print() const{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%f ", r[i][j]);
            if (j == 2) printf("\n");
        }
    }
}

double Matrix_3D::determinant() const{
    double det = this->r[0][0] * (this->r[1][1] * this->r[2][2] - this->r[1][2] * this->r[2][1]) -
        this->r[0][1] * (this->r[1][0] * this->r[2][2] - this->r[1][2] * this->r[2][0]) +
        this->r[0][2] * (this->r[1][0] * this->r[2][1] - this->r[1][1] * this->r[2][0]);
    return det;
}
Matrix_3D Matrix_3D::inverse() const{
        double det = this->determinant();

        if (det == 0.0) {
            printf("matrix is singular no inversion possible \n");
        }

        Matrix_3D inv;

        inv.r[0][0] = (this->r[1][1] * this->r[2][2] - this->r[1][2] * this->r[2][1]) / det;
        inv.r[0][1] = (this->r[0][2] * this->r[2][1] - this->r[0][1] * this->r[2][2]) / det;
        inv.r[0][2] = (this->r[0][1] * this->r[1][2] - this->r[0][2] * this->r[1][1]) / det;

        inv.r[1][0] = (this->r[1][2] * this->r[2][0] - this->r[1][0] * this->r[2][2]) / det;
        inv.r[1][1] = (this->r[0][0] * this->r[2][2] - this->r[0][2] * this->r[2][0]) / det;
        inv.r[1][2] = (this->r[0][2] * this->r[1][0] - this->r[0][0] * this->r[1][2]) / det;

        inv.r[2][0] = (this->r[1][0] * this->r[2][1] - this->r[1][1] * this->r[2][0]) / det;
        inv.r[2][1] = (this->r[0][1] * this->r[2][0] - this->r[0][0] * this->r[2][1]) / det;
        inv.r[2][2] = (this->r[0][0] * this->r[1][1] - this->r[0][1] * this->r[1][0]) / det;

        return inv;
}
template <typename T>
Matrix<T>::Matrix(int n, int m) : rows(n), cols(m), data(n, std::vector<T>(m, 0)) {}

template <typename T>
Matrix<T> Matrix<T>::Identity(int size) {
    Matrix<T> ret(size, size);
    for (int i = 0; i < size; ++i) {
        ret.data[i][i] = 1;
    }
    return ret;
}

template <typename T>
std::vector<T> Matrix<T>::operator*(const std::vector<T>& vec) const {
    if (vec.size() != cols) {
        printf("Vector size must match the number of matrix columns \n");
    }
    std::vector<T> result(rows, 0);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i] += data[i][j] * vec[j];
        }
    }
    return result;
}

template <typename T>
Vector<T> Matrix<T>::operator*(const Vector<T>& vec) const {
    if (vec.get_size() != cols) {
        printf("Vector size must match the number of matrix columns \n");
    }
    Vector<T> result(cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i] += data[i][j] * vec.data[j];
        }
    }
    return result;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other) {
    if (this != &other) {
        rows = other.rows;
        cols = other.cols;
        data = other.data;
    }
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
    if (cols != other.rows) {
        printf("Matrix dimensions must agree for multiplication\n");
    }
    Matrix<T> result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const T scalar) const {
    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
    if (rows != other.rows || cols != other.cols) {
        printf("Matrix dimensions must agree for addition\n");
    }
    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

template <typename T>
void Matrix<T>::print() const {
    for (const auto& row : data) {
        for (const auto& elem : row) {
            printf("%f ", elem) ;
        }
        printf("\n");
    }
}

template <typename T>
Matrix<T> Matrix<T>::submatrix(int excludeRow, int excludeCol) const {
    Matrix<T> sub(rows - 1, cols - 1);
    int subi = 0;
    for (int i = 0; i < rows; ++i) {
        if (i == excludeRow) continue;
        int subj = 0;
        for (int j = 0; j < cols; ++j) {
            if (j == excludeCol) continue;
            sub.data[subi][subj] = data[i][j];
            ++subj;
        }
        ++subi;
    }
    return sub;
}

template <typename T>
T Matrix<T>::determinant() const {
    if (rows != cols) {
        printf("Determinant can only be calculated for square matrices \n");
    }
    if (rows == 1) {
        return data[0][0];
    }
    if (rows == 2) {
        return data[0][0] * data[1][1] - data[0][1] * data[1][0];
    }
    T det = 0;
    for (int j = 0; j < cols; ++j) {
        det += (j % 2 == 0 ? 1 : -1) * data[0][j] * submatrix(0, j).determinant();
    }
    return det;
}

template <typename T>
Matrix<T> Matrix<T>::adjugate() const {
    if (rows != cols) {
        printf("Adjugate can only be calculated for square matrices \n");
    }
    Matrix<T> adj(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            adj.data[j][i] = ((i + j) % 2 == 0 ? 1 : -1) * submatrix(i, j).determinant();
        }
    }
    return adj;
}

template <typename T>
Matrix<T> Matrix<T>::inverse() const {
    if (rows != cols) {
        printf("Inverse can only be calculated for square matrices");
    }
    T det = determinant();
    if (det == 0) {
        printf("Matrix is singular and cannot be inverted.");
    }
    Matrix<T> adj = adjugate();
    return adj * (1 / det);
}

template <typename T>
Matrix<T> Matrix<T>::transpose() const {
    Matrix<T> result(cols, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[j][i] = data[i][j];
        }
    }
    return result;
}

template <typename T>
Vector<T>::Vector(std::vector<T> data) {
    this->data = data;
    this->size = data.size();
}
template <typename T>
Vector<T>::Vector(Vector_3D data) {
    this->data = std::vector<T>();
    this->data.push_back(data.x);
    this->data.push_back(data.y);
    this->data.push_back(data.z);
    this->size = 3;
}

template <typename T>
Vector<T>::Vector(int size) {
   this->data = std::vector<T>(size, 0);
   this->size = size;
}

template <typename T>
int Vector<T>::get_size() const{
    return size;
}

double lerp(double lly, double lry, double llx, double lrx, double x) {
    double distance = abs (lrx - llx);
    if (distance == 0) {
        return (lly + lry) / 2; 
    }
    double weight_left = lly * abs (lrx - x) / distance;
    double weight_right = lry * abs (llx - x) / distance;
    return weight_left + weight_right;
}

double linear_interpolation(double * x, double * y, double value, int len){
    if (x[0] > value) return y[0];
    for (int i = 0; i < len - 1; i++) {
        if (x[i] <= value && x[i+1] >= value) return lerp(y[i], y[i+1], x[i], x[i + 1], value);
    }
    return y[len];
}
