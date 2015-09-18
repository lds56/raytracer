//
// Created by Rui Chen on 9/15/15.
//


#include <math.h>
#include "Vector.h"

Vector2d Vector2d::operator =(const Vector2d &vector) {
    if (this == &vector) {
        return *this;
    }

    x = vector.x;
    y = vector.y;

    return *this;
}


Vector2d Vector2d::operator +(const Vector2d &vector) const {
    return Vector2d(x + vector.x, y + vector.y);
}


Vector2d Vector2d::operator -(const Vector2d &vector) const {
    return Vector2d(x - vector.x, y - vector.y);
}


Vector2d Vector2d::operator +=(const Vector2d &vector) {
    x += vector.x;
    y += vector.y;

    return *this;
}


Vector2d Vector2d::operator -=(const Vector2d &vector) {
    x -= vector.x;
    y -= vector.y;

    return *this;
}


Vector2d Vector2d::operator *(const float scalar) const {
    return Vector2d(x * scalar, y * scalar);
}


Vector2d Vector2d::operator /(const float scalar) const {
    float invScalar = 1.0f / scalar;
    return Vector2d(x * invScalar, y * invScalar);
}


Vector2d Vector2d::operator *=(const float scalar) {
    x *= scalar;
    y *= scalar;

    return *this;
}


Vector2d Vector2d::operator /=(const float scalar) {
    float invScalar = 1.0f / scalar;
    x *= scalar;
    y *= scalar;

    return *this;
}


float Vector2d::length() const {
    return sqrt(lengthSqr());
}


float Vector2d::lengthSqr() const {
    return x * x + y * y;
}


float Vector2d::normalize() {
    float len = length();
    *this /= len;

    return len;
}


Vector2d Vector2d::negate() {
    x = -x;
    y = -y;

    return *this;
}



/*----------2-3d------------*/


Vector3d Vector3d::operator =(const Vector3d &vector) {
    if (this == &vector) {
        return *this;
    }

    x = vector.x;
    y = vector.y;
    z = vector.z;

    return *this;
}


Vector3d Vector3d::operator +(const Vector3d &vector) const {
    return Vector3d(x + vector.x, y + vector.y, z + vector.z);
}


Vector3d Vector3d::operator -(const Vector3d &vector) const {
    return Vector3d(x - vector.x, y - vector.y, z - vector.z);
}


Vector3d Vector3d::operator +=(const Vector3d &vector) {
    x += vector.x;
    y += vector.y;
    z += vector.z;

    return *this;
}


Vector3d Vector3d::operator -=(const Vector3d &vector) {
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;

    return *this;
}


Vector3d Vector3d::operator *(const float scalar) const {
    return Vector3d(x * scalar, y * scalar, z * scalar);
}


Vector3d Vector3d::operator/(const float scalar) const {
    float invScalar = 1.0f / scalar;
    return Vector3d(x * invScalar, y * invScalar, z * invScalar);
}


Vector3d Vector3d::operator *=(const float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}


Vector3d Vector3d::operator /=(const float scalar) {
    x /= scalar;
    y /= scalar;
    z /= scalar;

    return *this;
}


float Vector3d::boxArea() const {
    return fabs(x * y) + fabs(y * z) + fabs(z * x);
}


Vector2d Vector3d::dropIndex(const int index) const {
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


int Vector3d::dominantIndex() const {
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

// function3d

float Vector3d::length() const {
    return sqrt(lengthSqr());
}


float Vector3d::lengthSqr() const {
    return x * x + y * y + z * z;
}


Vector3d Vector3d::norm() {
    return *this/length();
}

float Vector3d::normalize() {
    float len = length();
    *this /= len;

    return len;
}


Vector3d Vector3d::negate() {
    x = -x;
    y = -y;
    z = -z;

    return *this;
}

// function2d

float Vector2d::dotProduct(const Vector2d &u, const Vector2d &v) {
    return (u.x * v.x) +
           (u.y * v.y);
}

//function 3d

Vector3d Vector3d::crossProduct(const Vector3d &u, const Vector3d &v) {
    return Vector3d(u.y * v.z - u.z * v.y,
                    u.z * v.x - u.x * v.z,
                    u.x * v.y - u.y * v.x);
}


float Vector3d::dotProduct(const Vector3d &u, const Vector3d &v) {
    return (u.x * v.x) +
           (u.y * v.y) +
           (u.z * v.z);
}

