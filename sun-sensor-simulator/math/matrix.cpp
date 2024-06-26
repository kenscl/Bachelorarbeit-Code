#include "matrix.h"
#include "matlib.h"

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


/*
 * General Matrix Class
 */

template <typename T>
Matrix<T>::Matrix() {}
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
        throw std::logic_error("Vector size must match the number of matrix columns \n");
    }
    Vector<T> result(rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data.at(i) += data.at(i).at(j) * vec.data.at(j);
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
        throw std::logic_error("Matrix dimensions must agree for multiplication\n");
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
        throw std::logic_error("Matrix dimensions must agree for addition");
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
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::logic_error("Matrix dimensions must agree for addition");
    }
    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

template <typename T>
void Matrix<T>::print() const {
    printf("matrix: \n");
    for (const auto& row : data) {
        for (const auto& elem : row) {
            printf("%.5f ", elem) ;
        }
        printf("\n");
    }
}

template <typename T>
Matrix<T> Matrix<T>::submatrix(int excludeRow, int excludeCol) const {
    if (excludeRow < 0 || excludeRow >= rows || excludeCol < 0 || excludeCol >= cols) {
        throw std::out_of_range("Row or column to exclude is out of range");
    }
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
        throw std::logic_error("Determinant can only be calculated for square matrices");
    }
   int n = rows;
    std::vector<std::vector<T>> temp = data; 

    T det = 1;
    for (int i = 0; i < n; ++i) {
        T maxElem = temp[i][i];
        int maxRow = i;
        for (int k = i + 1; k < n; ++k) {
            if (std::abs(temp[k][i]) > std::abs(maxElem)) {
                maxElem = temp[k][i];
                maxRow = k;
            }
        }

        if (maxRow != i) {
            std::swap(temp[i], temp[maxRow]);
            det *= -1; 
        }
        if (temp[i][i] == 0) {
            return 0;
        }

        for (int k = i + 1; k < n; ++k) {
            T factor = temp[k][i] / temp[i][i];
            for (int j = i; j < n; ++j) {
                temp[k][j] -= factor * temp[i][j];
            }
        }
        det *= temp[i][i];
    }
    return det;

}

template <typename T>
Matrix<T> Matrix<T>::adjugate() const {
    if (rows != cols) {
        throw std::logic_error("Adjugate can only be calculated for square matrices");
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
        throw std::logic_error("Inverse can only be calculated for square matrices");
    }
    T det = determinant();
    if (det == 0) {
        throw std::logic_error("Matrix is singular and cannot be inverted.");
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
Vector<T> Matrix<T>::get_col(int col) const {
    if (col < 0 || col >= cols) {
        throw std::out_of_range("Column index out of range");
    }

    Vector<T> column(rows);
    for (int i = 0; i < rows; ++i) {
        column.data.at(i) = this->data.at(i).at(col);
    }
    return column;
}

template <typename T>
void Matrix<T>::swap_rows(int row1, int row2) {
    if (row1 < 0 || row1 >= rows || row2 < 0 || row2 >= rows) {
        throw std::out_of_range("Row index out of range");
    }

    for (int j = 0; j < cols; ++j) {
        std::swap(this->data.at(row1).at(j), this->data.at(row2).at(j));
    }
}

template <typename T>
Vector<T> gaussian_elimination(Matrix<T> A, Vector<T> b) {
       int n = A.size();

       for (int i = 0; i < n - 1; ++i) {
           int pivot_row = i;
           for (int k = i + 1; k < n; ++k) {
               if (std::abs(A.data[k][i]) > std::abs(A.data[pivot_row][i])) {
                   pivot_row = k;
               }
           }
           if (pivot_row != i) {
               A = A.swap_rows(i, pivot_row);
               b.data.swap(i, pivot_row);
           }

           for (int k = i + 1; k < n; ++k) {
               double factor = A.data[k][i] / A.data[i][i];
               for (int j = i; j < n; ++j) {
                   A.data[k][j] -= factor * A.data[i][j];
               }
               b.data[k] -= factor * b.data[i];
           }
       }

       // Back substitution
       Vector<T> x(n);
       for (int i = n - 1; i >= 0; --i) {
           double sum = 0.0;
           for (int j = i + 1; j < n; ++j) {
               sum += A.data[i][j] * x.data[j];
           }
           x.data[i] = (b.data[i] - sum) / A.data[i][i];
       }

       return x;

}

template <typename T>
void Matrix<T>::QR_decomp(Matrix<T> &A, Matrix<T> &Q, Matrix<T> &R) {
    if (A.cols != A.rows) {
        throw std::logic_error("A is not suited to QR decomposition");
    }
    int n = A.rows;
    Matrix<double> A_cp = A;
    Q = Matrix<double>::Identity(n);

    for (int k = 0; k < n; ++k) {
        // Find Householder reflector
        Vector<double> x = A_cp.get_col(k);
        for (int i = 0; i < k; ++i) {
            x.data[i] = 0; // Zero out the upper part
        }
        double alpha = x.norm();
        if (A.data[k][k] < 0) {
            alpha = abs(alpha);
        }
        else {
            alpha = -abs(alpha);
        }

        Vector<double> e(n);
        e.data[k] = 1.0;
        Vector<double> v = (x + e * alpha).normalize();

        Matrix<double> v_mat(n, 1);
        for (int i = 0; i < n; ++i) {
            v_mat.data[i][0] = v.data[i];
        }
        Matrix<double> H = Matrix<double>::Identity(n) - (v_mat * v_mat.transpose()) * 2.0;

        A_cp = H * A_cp;
        Q = Q * H.transpose();
    }

    R = A_cp;
    Q = Q; // Q should be orthogonal
}

//helper
template <typename T>
bool has_Converged(Vector<T>& diagonal, const Vector<T>& prevDiagonal, double tolerance) {
    for (size_t i = 0; i < diagonal.size; ++i) {
        if (fabs(diagonal.data.at(i) - prevDiagonal.data.at(i)) > tolerance) {
            return false;
        }
    }
    return true;
}

template <typename T>
Vector<T> back_substitution(Matrix<T> &R, Vector<T> &b) {
    int n = R.rows;
    Vector<T> x(n);

    for (int i = n - 1; i >= 0; --i) {
        T sum = 0;
        for (int j = i + 1; j < n; ++j) {
            sum += R.data[i][j] * x.data[j];
        }
        x.data[i] = (b.data[i] - sum) / R.data[i][i];
    }

    return x;
}

template <typename T>
void Matrix<T>::eigen(Matrix<T> &eigen_vectors, Vector<T> &eigen_values, double tolerance){
    int n = this->cols; 
    Matrix <T> A = *this;

    eigen_values = Vector<T>(n);
    eigen_vectors = Matrix<T>::Identity(n);
    Vector<T> prev_diag(n);

    Matrix<T> Q;
    Matrix<T> R;
    do {
        prev_diag = eigen_values;

        QR_decomp(A, Q, R);
        A = Q.transpose() * A * Q;

        for (int i = 0; i < n; ++i) {
            eigen_values.data.at(i) = A.data.at(i).at(i);
        }
    } while (!has_Converged(eigen_values, prev_diag, tolerance));

}

template <typename T>
Matrix<T> Matrix<T>::singular_value_decomposition(Matrix<T>& U, Matrix<T>& S, Matrix<T>& V) const {
    Matrix<T> ATA = this->transpose() * (*this);
    Matrix<T> AAT = (*this) * this->transpose();

    Vector<T> singular_values;
    S = Matrix<T>(this->rows, this->cols);

    ATA.eigen(V, singular_values);
    AAT.eigen(U, singular_values);

    for (int i = 0; i < singular_values.size; i++) {
        if (singular_values.data.at(i) < 0) {
            singular_values.data.at(i) = -singular_values.data.at(i);
            for (int j = 0; j < V.data.at(i).size(); j++) {
                V.data.at(i).at(j) = V.data.at(i).at(j) * -1; 
            }
        } 
        singular_values.data.at(i) = sqrt(singular_values.data.at(i));
    }

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            if (i == j && i < singular_values.size) {
                S.data.at(i).at(j) = singular_values.data.at(i);
            } else {
                S.data.at(i).at(j) = 0;
            }
        }
    }

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::moore_penrose() {
    Matrix<T> V, S, U;
    this->singular_value_decomposition(U, S, V);
    Matrix<T> S_plus = S;

    for (int i = 0; i < S_plus.rows; i++) {
        for (int j = 0; j < S_plus.cols; j++) {
            if (S_plus.data.at(i).at(j) != 0) {
                S_plus.data.at(i).at(j) = 1 / S_plus.data.at(i).at(j);
            }
        }
    }
    S_plus = S_plus.transpose();

    Matrix<T> inv;
    inv = V * S_plus * U.transpose();

    return inv;
}
