#include "matlib.h"

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

