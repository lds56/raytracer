//
// Created by Rui Chen on 9/14/15.
//

#ifndef RAYTRACER_VECTOR_H
#define RAYTRACER_VECTOR_H

#include <cstdio>
#include "Definition.h"

class Vector2d {
public:
    float x, y;

    Vector2d() {}
    Vector2d(float x, float y): x(x), y(y) {}
    Vector2d(Vec2f pos): x(pos[0]), y(pos[1]) {}

    Vector2d operator=(const Vector2d &vector);

    Vector2d operator+(const Vector2d &vector) const;
    Vector2d operator-(const Vector2d &vector) const;
    Vector2d operator+=(const Vector2d &vector);
    Vector2d operator-=(const Vector2d &vector);

    Vector2d operator*(const float scalar) const;
    Vector2d operator/(const float scalar) const;
    Vector2d operator*=(const float scalar);
    Vector2d operator/=(const float scalar);

    float length() const;
    float lengthSqr() const;
    float normalize();
    Vector2d negate();

    static float dotProduct(const Vector2d &u, const Vector2d &v);
};


class Vector3d {
public:
    float x, y, z;

    Vector3d() {}
    Vector3d(Vec3f pos): x(pos[0]), y(pos[1]), z(pos[2]) {}
    Vector3d(const float x, const float y, const float z):
            x(x), y(y), z(z) {}

    Vector3d operator=(const Vector3d &vector);

    Vector3d operator+(const Vector3d &vector) const;
    Vector3d operator-(const Vector3d &vector) const;
    Vector3d operator+=(const Vector3d &vector);
    Vector3d operator-=(const Vector3d &vector);

    Vector3d operator*(const float scalar) const;
    Vector3d operator/(const float scalar) const;
    Vector3d operator*=(const float scalar);
    Vector3d operator/=(const float scalar);

    int dominantIndex() const;
    float boxArea() const;
    float length() const;
    float lengthSqr() const;
    float normalize();
    Vector2d dropIndex(const int index) const;
    Vector3d norm();
    Vector3d negate();

    void print(char * id) const {
        printf("Vector %s: %f, %f, %f\n", id, x, y, z);
    }

    static Vector3d crossProduct(const Vector3d &u, const Vector3d &v);
    static float dotProduct(const Vector3d &u, const Vector3d &v);
};



#endif //RAYTRACER_VECTOR_H
