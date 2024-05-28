#include <gtest/gtest.h>
#include "../math/matrix.h" // Assuming you have your Matrix_3D and Matrix classes in matrix.h

TEST(Matrix3DTest, Determinant) {
    Matrix_3D mat;
    mat.r[0][0] = 1; mat.r[0][1] = 2; mat.r[0][2] = 3;
    mat.r[1][0] = 0; mat.r[1][1] = 1; mat.r[1][2] = 4;
    mat.r[2][0] = 5; mat.r[2][1] = 6; mat.r[2][2] = 0;

    EXPECT_NEAR(mat.determinant(), 1, 1e-9);
}

TEST(Matrix3DTest, Inverse) {
    Matrix_3D mat;
    mat.r[0][0] = 1; mat.r[0][1] = 2; mat.r[0][2] = 3;
    mat.r[1][0] = 0; mat.r[1][1] = 1; mat.r[1][2] = 4;
    mat.r[2][0] = 5; mat.r[2][1] = 6; mat.r[2][2] = 0;

    Matrix_3D inv = mat.inverse();

    Matrix_3D identity = mat * inv;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) {
                EXPECT_NEAR(identity.r[i][j], 1.0, 1e-9);
            } else {
                EXPECT_NEAR(identity.r[i][j], 0.0, 1e-9);
            }
        }
    }
}

TEST(MatrixTest, Identity) {
    Matrix<double> identity = Matrix<double>::Identity(3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) {
                EXPECT_DOUBLE_EQ(identity.data[i][j], 1.0);
            } else {
                EXPECT_DOUBLE_EQ(identity.data[i][j], 0.0);
            }
        }
    }
}

TEST(MatrixTest, Determinant) {
    Matrix<double> mat(3, 3);
    mat.data = {{1, 2, 3},
                {0, 1, 4},
                {5, 6, 0}};

    EXPECT_NEAR(mat.determinant(), 1.0, 1e-9);
}

TEST(MatrixTest, Inverse) {
    Matrix<double> mat(3, 3);
    mat.data = {{1, 2, 3},
                {0, 1, 4},
                {5, 6, 0}};

    Matrix<double> inv = mat.inverse();

    Matrix<double> identity = mat * inv;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) {
                EXPECT_NEAR(identity.data[i][j], 1.0, 1e-9);
            } else {
                EXPECT_NEAR(identity.data[i][j], 0.0, 1e-9);
            }
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

