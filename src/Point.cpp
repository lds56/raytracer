//
// Created by Rui Chen on 9/15/15.
//

#include "Point.h"
#include "Utils.h"
#include "Matrix.h"
#include <vector>

using namespace std;

Point2d::Point2d() {}
Point2d::Point2d(float u, float v): u(u), v(v) {}
Point2d::Point2d(Vec2f pos): Point2d(pos[0], pos[1]) {}
Point2d::Point2d(Vector2d x): Point2d(x.u, x.v) {}

Point2d Point2d::operator=(const Point2d &point) {
    if (this == &point) {
        return *this;
    }

    u = point.u;
    v = point.v;

    return *this;
}

bool Point2d::operator==(const Point2d &point) {
    if (u == point.u && v == point.v) return true;
    else return false;
}

Vector2d Point2d::operator-(const Point2d &point) const {
    return Vector2d(u - point.u, v - point.v);
}

Point2d Point2d::operator+(const Point2d &point) const {
    return Point2d(u - point.u, v - point.v);
}

Point2d Point2d::operator+(const Vector2d &vector) const {
    return Point2d(u + vector.u, v + vector.v);
}


Point2d Point2d::operator-(const Vector2d &vector) const {
    return Point2d(u - vector.u, v - vector.v);
}


Point2d Point2d::operator+=(const Vector2d &vector) {
    u += vector.u;
    v += vector.v;

    return *this;
}


Point2d Point2d::operator-=(const Vector2d &vector) {
    u -= vector.u;
    v -= vector.v;

    return *this;
}



Point2d Point2d::operator*(const float scalar) const {
    return Point2d(u * scalar, v * scalar);
}


Point2d Point2d::operator/(const float scalar) const {
    float invScalar = 1.0f / scalar;
    return Point2d(u * invScalar, v * invScalar);
}


Point2d Point2d::operator*=(const float scalar) {
    u *= scalar;
    v *= scalar;

    return *this;
}


Point2d Point2d::operator/=(const float scalar) {
    float invScalar = 1.0f / scalar;
    u *= scalar;
    v *= scalar;

    return *this;
}

float Point2d::operator()(const int idx) {
    switch (idx) {
        case 1: return u;
        case 2: return v;
        default:
            Utils::logError("Undefined coordination index!");
            exit(1);
    }
}

bool Point2d::isNullPoint() {return this == &Point2d::NullPoint;}

const Point2d Point2d::NullPoint = Point2d(233, 233);

const Point2d& Point2d::getNullPoint() {
    return Point2d::NullPoint;
}

/*----------2-3d----------*/


Point3d::Point3d() {}
Point3d::Point3d(float x, float y, float z): x(x), y(y), z(z) {}
Point3d::Point3d(Vec3f pos): Point3d(pos[0], pos[1], pos[2]) {}
Point3d::Point3d(Vector3d v): Point3d(v.x, v.y, v.z) {}

Point3d Point3d::operator=(const Point3d &point) {
    if (this == &point) {
        return *this;
    }

    x = point.x;
    y = point.y;
    z = point.z;

    return *this;
}

bool Point3d::operator==(const Point3d &point) {
    if (x == point.x && y == point.y && z == point.z) return true;
    else return false;
}

Vector3d Point3d::operator-(const Point3d &point) const {
    return Vector3d(x - point.x, y - point.y, z - point.z);
}

Point3d Point3d::operator+(const Point3d &point) const {
    return Point3d(x - point.x, y - point.y, z - point.z);
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

float Point3d::operator()(const int idx) {
    switch (idx) {
        case 1: return x;
        case 2: return y;
        case 3: return z;
        default:
            Utils::logError("Undefined coordination index!");
            exit(1);
    }
}

Point2d Point3d::projectTo(int coord) {
    switch (coord) {
        case 1: return Point2d(y, z);
        case 2: return Point2d(x, z);
        case 3: return Point2d(x, y);
        default: {
            Utils::logError("Wrong coordinate!");
            exit(1);
        }
    }
}


vector<float> Point3d::toVector() {
    return vector<float>{x, y, z};
}

Matrix<float> Point3d::toMatrix() {
    vector<vector<float>> v;
    v.push_back(this->toVector());
    return Matrix<float>(1, 3, v).transpose();
}

bool Point3d::isNullPoint() {return this == &Point3d::NullPoint;}

const Point3d Point3d :: NullPoint = Point3d(233, 233, 233);

const Point3d& Point3d::getNullPoint() {
    return Point3d::NullPoint;
}



// function2d

float Point2d::dotProduct(const Point2d &a, const Point2d &b) {
    return a.u * b.u + a.v * b.v;
}
float Point2d::dotProduct(const Point2d &a, const Vector2d &b) {
    return a.u * b.u + a.v * b.v;
}
float Point2d::dotProduct(const Vector2d &a, const Point2d &b) {
    return a.u * b.u + a.v * b.v;
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

float Point3d::EuDistance(Point3d &a, Point3d &b) {
    return (a-b).length();
}

float Point3d::EuDistanceSqr(Point3d &a, Point3d &b) {
    return (a-b).lengthSqr();
}