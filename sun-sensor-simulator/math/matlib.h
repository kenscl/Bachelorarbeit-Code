#ifndef __MATLIB
#define __MATLIB
#include "math.h"
#include <vector>

// Math includes:
#include "matrix.h"
#include "quaternion.h"

// constants
# define PI                 3.14159265359
# define C                  299792458.0
# define PLANCK_CONSTANT    6.62607015e-34
# define BOLTZMANN_CONSTANT 1.380649e-23

#define R2D     180 / M_PI
#define D2R     M_PI / 180

class Vector_3D;
class Matrix_3D;
template <typename T>
class Vector;

class Vector_3D {
    public: 
        double x,y,z;

    public: 
        Vector_3D();
        Vector_3D(double x, double y, double z);
        Vector_3D(Vector_3D const &other);

        Vector_3D cross_product(Vector_3D other) const;
        double norm() const;
        Vector_3D normalize() const;
        void print() const;
        double calculate_angle(Vector_3D other) const;
        Matrix_3D rmat_to(Vector_3D target) const;
        double distance_to(Vector_3D other) const;

        Vector_3D operator*(double value) const;
        Vector_3D operator/(double value) const;
        bool operator==(Vector_3D other) const;

        double operator*(Vector_3D other) const;
        Vector_3D operator+(Vector_3D other) const;
        Vector_3D operator-(Vector_3D other) const;
};

template <typename T>
class Vector {
    public:
        std::vector<T> data;
        int size;
    public:
        Vector(std::vector<T> data);
        Vector(Vector_3D data);
        Vector(int size);
        Vector() : size(0) {}

        int get_size() const;
        double calculate_angle(Vector<T> other) const;
        void print() const;
        T norm() const;
        Vector<T> normalize() const;
        Matrix<T> transpose() const;
        
        Vector<T> operator*(double d) const;
        T operator*(Vector<T> other) const;
        Vector<T> operator/(double d) const;
        Vector<T> operator-(const Vector<T> other) const;
        Vector<T> operator+(const Vector<T> other) const;
        Vector<T>& operator=(const Vector<T>& other);
};

double lerp(double lly, double lry, double llx, double lrx, double x);
double linear_interpolation(double * x, double * y, double value, int len);
double rmse(std::vector<double> u, std::vector<double> v);

template class Vector<double>;
#endif

