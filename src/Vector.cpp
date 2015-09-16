//
// Created by Rui Chen on 9/15/15.
//


#include <math.h>
#include "Vector.h"

inline Vector2d Vector2d::operator =(const Vector2d &vector) {
    if (this == &vector) {
        return *this;
    }

    x = vector.x;
    y = vector.y;

    return *this;
}


inline Vector2d Vector2d::operator +(const Vector2d &vector) const {
    return Vector2d(x + vector.x, y + vector.y);
}


inline Vector2d Vector2d::operator -(const Vector2d &vector) const {
    return Vector2d(x - vector.x, y - vector.y);
}


inline Vector2d Vector2d::operator +=(const Vector2d &vector) {
    x += vector.x;
    y += vector.y;

    return *this;
}


inline Vector2d Vector2d::operator -=(const Vector2d &vector) {
    x -= vector.x;
    y -= vector.y;

    return *this;
}


inline Vector2d Vector2d::operator *(const float scalar) const {
    return Vector2d(x * scalar, y * scalar);
}


inline Vector2d Vector2d::operator /(const float scalar) const {
    float invScalar = 1.0f / scalar;
    return Vector2d(x * invScalar, y * invScalar);
}


inline Vector2d Vector2d::operator *=(const float scalar) {
    x *= scalar;
    y *= scalar;

    return *this;
}


inline Vector2d Vector2d::operator /=(const float scalar) {
    float invScalar = 1.0f / scalar;
    x *= scalar;
    y *= scalar;

    return *this;
}


inline float Vector2d::length() const {
    return sqrt(lengthSqr());
}


inline float Vector2d::lengthSqr() const {
    return x * x + y * y;
}


inline float Vector2d::normalize() {
    float len = length();
    *this /= len;

    return len;
}


inline Vector2d Vector2d::negate() {
    x = -x;
    y = -y;

    return *this;
}



/*----------2-3d------------*/


inline Vector3d Vector3d::operator =(const Vector3d &vector) {
    if (this == &vector) {
        return *this;
    }

    x = vector.x;
    y = vector.y;
    z = vector.z;

    return *this;
}


inline Vector3d Vector3d::operator +(const Vector3d &vector) const {
    return Vector3d(x + vector.x, y + vector.y, z + vector.z);
}


inline Vector3d Vector3d::operator -(const Vector3d &vector) const {
    return Vector3d(x - vector.x, y - vector.y, z - vector.z);
}


inline Vector3d Vector3d::operator +=(const Vector3d &vector) {
    x += vector.x;
    y += vector.y;
    z += vector.z;

    return *this;
}


inline Vector3d Vector3d::operator -=(const Vector3d &vector) {
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;

    return *this;
}


inline Vector3d Vector3d::operator *(const float scalar) const {
    return Vector3d(x * scalar, y * scalar, z * scalar);
}


inline Vector3d Vector3d::operator /(const float scalar) const {
    float invScalar = 1.0f / scalar;
    return Vector3d(x * invScalar, y * invScalar, z * invScalar);
}


inline Vector3d Vector3d::operator *=(const float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}


inline Vector3d Vector3d::operator /=(const float scalar) {
    x /= scalar;
    y /= scalar;
    z /= scalar;

    return *this;
}


inline float Vector3d::boxArea() const {
    return fabs(x * y) + fabs(y * z) + fabs(z * x);
}


inline Vector2d Vector3d::dropIndex(const int index) const {
    switch (index % 3) {
        case 0:
            return Vector2d(y, z);
        case 1:
            return Vector2d(x, z);
        case 2:
            return Vector2d(x, y);
    }

    return Vector2d();
}


inline int Vector3d::dominantIndex() const {
    float abs_x = fabs(x),
            abs_y = fabs(y),
            abs_z = fabs(z);
    if (abs_x > abs_y) {
        if (abs_x > abs_z) {
            return x > 0? 0: 3;
        } else {
            return z > 0? 2: 5;
        }
    } else {
        if (abs_y > abs_z) {
            return y > 0? 1: 4;
        } else {
            return z > 0? 2: 5;
        }
    }
}


inline float Vector3d::length() const {
    return sqrt(lengthSqr());
}


inline float Vector3d::lengthSqr() const {
    return x * x + y * y + z * z;
}


inline Vector3d Vector3d::norm() {
    return *this/length();
}

inline float Vector3d::normalize() {
    float len = length();
    *this /= len;

    return len;
}


inline Vector3d Vector3d::negate() {
    x = -x;
    y = -y;
    z = -z;

    return *this;
}

