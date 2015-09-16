//
// Created by Rui Chen on 9/14/15.
//

#ifndef RAYTRACER_POINT_H
#define RAYTRACER_POINT_H

#include "Vector.h"
#include "definition.h"
#include <vector>

using namespace std;

class Point2d {
public:

    float x, y;

    Point2d(): Vector2d() {}
    Point2d(Vec2f pos): Vector2d(pos) {}
    Point2d(float x, float y): Vector2d(x, y) {}

    inline Point2d& operator =(const Point2d &point);

    inline Vector2d operator -(const Point2d &point) const;

    inline Point2d operator +(const Vector2d &vector) const;
    inline Point2d operator -(const Vector2d &vector) const;
    inline Point2d& operator +=(const Vector2d &vector);
    inline Point2d& operator -=(const Vector2d &vector);

    const static NullPoint = Point2d(233, 233);
};


inline float dotProduct(const Point2d &a, const Point2d &b) {
    return a.x * b.x + a.y * b.y;
}
inline float dotProduct(const Point2d &a, const Vector2d &b) {
    return a.x * b.x + a.y * b.y;
}
inline float dotProduct(const Vector2d &a, const Point2d &b) {
    return a.x * b.x + a.y * b.y;
}


class Point3d {
public:

    float x, y, z;

    Point3d(): Vector3d() {}
    Point3d(Vec3f pos): Vector3d(pos) {}
    Point3d(float x, float y, float z): Vector3d(x, y, z) {}

    inline Point3d& operator =(const Point3d &point);

    inline Vector3d operator -(const Point3d &point) const;

    inline Point3d operator +(const Vector3d &vector) const;
    inline Point3d operator -(const Vector3d &vector) const;
    inline Point3d& operator +=(const Vector3d &vector);
    inline Point3d& operator -=(const Vector3d &vector);

    inline Point3d operator *(const float scalar) const;
    inline Point3d& operator *=(const float scalar);

    const static Point3d NullPoint = Point3d(233, 233, 233);
};


inline float dotProduct(const Point3d &a, const Point3d &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
inline float dotProduct(const Point3d &a, const Vector3d &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
inline float dotProduct(const Vector3d &a, const Point3d &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline Point3d pointMax(const Point3d &a, const Point3d &b) {
    return Point3d(std::max(a.x, b.x), std::max(a.y, b.y), std::max(a.z, b.z));
}

inline Point3d pointMin(const Point3d &a, const Point3d &b) {
    return Point3d(std::min(a.x, b.x), std::min(a.y, b.y), std::min(a.z, b.z));
}


#endif //RAYTRACER_POINT_H
