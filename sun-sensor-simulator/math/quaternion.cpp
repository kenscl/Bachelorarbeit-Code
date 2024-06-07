#include "quaternion.h"

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
Quaternion<T>::Quaternion(T angle, Vector<T> axis) {
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
            q * other.j + j * other.q + k * other.i - i * other.k,
            q * other.k + k * other.q + i * other.j - j * other.i
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
