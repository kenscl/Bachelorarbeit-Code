#ifndef __QUATERNION
#define __QUATERNION
#include "math.h"

template <typename T>
class Vector;

template <typename T>
class Quaternion {
    public:
        T q, i, j, k;
    public: 
        Quaternion();
        Quaternion(T q, T i, T j, T k);
        Quaternion(T angle, const Vector<T>& axis);

        Quaternion<T> operator*(const Quaternion<T>& other) const;

        Quaternion<T>& operator=(const Quaternion<T>& other);
        Quaternion<T> conjugate() const;
        void print() const;
};

template class Quaternion<double>;
#endif
