#include <gtest/gtest.h>
#include "../math/matrix.h" 
#include "../math/matlib.h"

TEST(Matrix, QR_DECOMP) {
    Matrix<double> A(3,3), Q(3,3), R(3,3);
    A.data[0][0] = 1;
    A.data[0][1] = 2;
    A.data[0][2] = 3;

    A.data[1][0] = 4;
    A.data[1][1] = 5;
    A.data[1][2] = 6;

    A.data[2][0] = 7;
    A.data[2][1] = 8;
    A.data[2][2] = 9;

    A.data[0][0] = 12;
    A.data[0][1] = -51;
    A.data[0][2] = 4;

    A.data[1][0] = 6;
    A.data[1][1] = 167;
    A.data[1][2] = -68;

    A.data[2][0] = -4;
    A.data[2][1] = 24;
    A.data[2][2] = -41;

    A.QR_decomp(A, Q, R);

    Matrix<double> A_test = (Q * R);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3;j++) {
             EXPECT_NEAR(A.data[i][j], A_test.data[i][j], 1e-6);
        }
    }
    Q.print();
    R.print();
}

TEST(Matrix, EIGEN) {
    Matrix<double> A(3,3);
    A.data[0][0] = 1;
    A.data[0][1] = 2;
    A.data[0][2] = 3;

    A.data[1][0] = 4;
    A.data[1][1] = 5;
    A.data[1][2] = 6;

    A.data[2][0] = 7;
    A.data[2][1] = 8;
    A.data[2][2] = 9;

    Vector<double> eigen_values;
    Matrix<double> eigen_vectors;

    A.eigen(eigen_vectors, eigen_values);
    eigen_vectors.print();
    eigen_values.print();
    for (int i = 0; i < eigen_values.size; i++) {
        Vector<double> Av = A * eigen_vectors.get_col(i);
        Vector<double> lv = eigen_vectors.get_col(i) * eigen_values.data.at(i);
        for(int j = 0; j < Av.size; ++j){
            EXPECT_NEAR(Av.data.at(j), lv.data.at(j), 1e-6);
        }

    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

