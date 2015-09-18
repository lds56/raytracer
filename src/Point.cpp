//
// Created by Rui Chen on 9/15/15.
//

#include "Point.h"


Point2d Point2d::operator=(const Point2d &point) {
    if (this == &point) {
        return *this;
    }

    x = point.x;
    y = point.y;

    return *this;
}

Vector2d Point2d::operator-(const Point2d &point) const {
    return Vector2d(x - point.x, y - point.y);
}


Point2d Point2d::operator+(const Vector2d &vector) const {
    return Point2d(x + vector.x, y + vector.y);
}


Point2d Point2d::operator-(const Vector2d &vector) const {
    return Point2d(x - vector.x, y - vector.y);
}


Point2d Point2d::operator+=(const Vector2d &vector) {
    x += vector.x;
    y += vector.y;

    return *this;
}


Point2d Point2d::operator-=(const Vector2d &vector) {
    x -= vector.x;
    y -= vector.y;

    return *this;
}



Point2d Point2d::operator*(const float scalar) const {
    return Point2d(x * scalar, y * scalar);
}


Point2d Point2d::operator/(const float scalar) const {
    float invScalar = 1.0f / scalar;
    return Point2d(x * invScalar, y * invScalar);
}


Point2d Point2d::operator*=(const float scalar) {
    x *= scalar;
    y *= scalar;

    return *this;
}


Point2d Point2d::operator/=(const float scalar) {
    float invScalar = 1.0f / scalar;
    x *= scalar;
    y *= scalar;

    return *this;
}

const Point2d Point2d::NullPoint = Point2d(233, 233);

/*----------2-3d----------*/

Point3d Point3d::operator=(const Point3d &point) {
    if (this == &point) {
        return *this;
    }

    x = point.x;
    y = point.y;
    z = point.z;

    return *this;
}


Vector3d Point3d::operator-(const Point3d &point) const {
    return Vector3d(x - point.x, y - point.y, z - point.z);
}


Point3d Point3d::operator+(const Vector3d &vector) const {
    return Point3d(x + vector.x, y + vector.y, z + vector.z);
}


Point3d Point3d::operator-(const Vector3d &vector) const {
    return Point3d(x - vector.x, y - vector.y, z - vector.z);
}


Point3d Point3d::operator+=(const Vector3d &vector) {
    x += vector.x;
    y += vector.y;
    z += vector.z;

    return *this;
}


Point3d Point3d::operator-=(const Vector3d &vector) {
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;

    return *this;
}


Point3d Point3d::operator*(const float scalar) const {
    return Point3d(x * scalar, y * scalar, z * scalar);
}

Point3d Point3d::operator*=(const float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}

Point3d Point3d::operator/(const float scalar) const {
    float invScalar = 1.0f / scalar;
    return Point3d(x * invScalar, y * invScalar, z * invScalar);
}

Point3d Point3d::operator/=(const float scalar) {
    x /= scalar;
    y /= scalar;
    z /= scalar;

    return *this;
}


const Point3d Point3d :: NullPoint = Point3d(233, 233, 233);

// function2d

float Point2d::dotProduct(const Point2d &a, const Point2d &b) {
    return a.x * b.x + a.y * b.y;
}
float Point2d::dotProduct(const Point2d &a, const Vector2d &b) {
    return a.x * b.x + a.y * b.y;
}
float Point2d::dotProduct(const Vector2d &a, const Point2d &b) {
    return a.x * b.x + a.y * b.y;
}


//  function3d

float Point3d::dotProduct(const Point3d &a, const Point3d &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
float Point3d::dotProduct(const Point3d &a, const Vector3d &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
float Point3d::dotProduct(const Vector3d &a, const Point3d &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Point3d Point3d::pointMax(const Point3d &a, const Point3d &b) {
    return Point3d(std::max(a.x, b.x), std::max(a.y, b.y), std::max(a.z, b.z));
}

Point3d Point3d::pointMin(const Point3d &a, const Point3d &b) {
    return Point3d(std::min(a.x, b.x), std::min(a.y, b.y), std::min(a.z, b.z));
}
