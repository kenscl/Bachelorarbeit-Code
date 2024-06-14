#include "quaternion.h"
#include "matlib.h"

template <typename T>
class Vector;

template <typename T>
Quaternion<T>::Quaternion() {
    this->q = 0;
    this->i = 0;
    this->j = 0;
    this->k = 0;
}

template <typename T>
Quaternion<T>::Quaternion(T q, T i, T j, T k) {
    this->q = q;
    this->i = i;
    this->j = j;
    this->k = k;
}

template <typename T>
Quaternion<T>::Quaternion(T angle, const Vector<T>& axis) {
    this->q = cos(angle / 2);
    this->i = axis.data.at(0) * sin(angle / 2);
    this->j = axis.data.at(1) * sin(angle / 2);
    this->k = axis.data.at(2) * sin(angle / 2);
}

template <typename T>
Quaternion<T> Quaternion<T>::operator*(const Quaternion<T>& other) const {
    return Quaternion<T>(
        q * other.q - i * other.i - j * other.j - k * other.k,  
        q * other.i + i * other.q + j * other.k - k * other.j,  
        q * other.j - i * other.k + j * other.q + k * other.i,  
        q * other.k + i * other.j - j * other.i + k * other.q   
    );
}

template <typename T>
Quaternion<T> Quaternion<T>::conjugate() const {
    return Quaternion<T>(q, -i, -j, -k);
}

template <typename T>
Quaternion<T>& Quaternion<T>::operator=(const Quaternion<T>& other) {
    if (this != &other) {  
        this->q = other.q;
        this->i = other.i;
        this->j = other.j;
        this->k = other.k;
    }
    return *this;
}

template <typename T>
void Quaternion<T>::print() const {
    printf("quaternion: \n");
    printf("q %.5f \n", this->q);
    printf("i %.5f \n", this->i);
    printf("j %.5f \n", this->j);
    printf("k %.5f \n", this->k);
}
