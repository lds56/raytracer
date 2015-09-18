//
// Created by Rui Chen on 9/14/15.
//

#ifndef RAYTRACER_POINT_H
#define RAYTRACER_POINT_H

#include "Vector.h"
#include <vector>

using namespace std;

class Point2d {
public:

    float x, y;

    Point2d() {}
    Point2d(float x, float y): x(x), y(y) {}
    Point2d(Vec2f pos): Point2d(pos[0], pos[1]) {}

    Point2d operator=(const Point2d &point);

    Vector2d operator-(const Point2d &point) const;

    Point2d operator+(const Vector2d &vector) const;
    Point2d operator-(const Vector2d &vector) const;
    Point2d operator+=(const Vector2d &vector);
    Point2d operator-=(const Vector2d &vector);

    Point2d operator*(const float scalar) const;
    Point2d operator/(const float scalar) const;
    Point2d operator*=(const float scalar);
    Point2d operator/=(const float scalar);

    static float dotProduct(const Point2d &a, const Point2d &b);
    static float dotProduct(const Point2d &a, const Vector2d &b);
    static float dotProduct(const Vector2d &a, const Point2d &b);

    const static Point2d NullPoint;
};



class Point3d {
public:

    float x, y, z;

    Point3d() {}
    Point3d(float x, float y, float z): x(x), y(y), z(z) {}
    Point3d(Vec3f pos): Point3d(pos[0], pos[1], pos[2]) {}

    Point3d operator=(const Point3d &point);

    Vector3d operator-(const Point3d &point) const;

    Point3d operator+(const Vector3d &vector) const;
    Point3d operator-(const Vector3d &vector) const;
    Point3d operator+=(const Vector3d &vector);
    Point3d operator-=(const Vector3d &vector);

    Point3d operator*(const float scalar) const;
    Point3d operator*=(const float scalar);
    Point3d operator/(const float scalar) const;
    Point3d operator/=(const float scalar);

    static float dotProduct(const Point3d &a, const Point3d &b);
    static float dotProduct(const Point3d &a, const Vector3d &b);
    static float dotProduct(const Vector3d &a, const Point3d &b);
    static Point3d pointMax(const Point3d &a, const Point3d &b);
    static Point3d pointMin(const Point3d &a, const Point3d &b);

    const static Point3d NullPoint;
};


#endif //RAYTRACER_POINT_H
