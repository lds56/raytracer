//
// Created by Rui Chen on 9/14/15.
//

#ifndef RAYTRACER_VECTOR_H
#define RAYTRACER_VECTOR_H

#include <cstdio>
#include <vector>
#include "Point.h"
#include "Matrix.h"
#include "Definition.h"

using namespace std;

class Vector2d {
public:
    float u, v;

    Vector2d() {}
    Vector2d(float u, float v): u(u), v(v) {}
    Vector2d(Vec2f pos): u(pos[0]), v(pos[1]) {}

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
    Vector3d(const float x, const float y, const float z): x(x), y(y), z(z) {}

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
    vector<float> toVector();
    Matrix<float> toMatrix();
    Point3d toPoint();

    float cosThetaWith(Vector3d vector);

    void print(char * id) const {
        printf("Vector %s: %f, %f, %f\n", id, x, y, z);
    }

    static Vector3d crossProduct(const Vector3d &u, const Vector3d &v);
    static float dotProduct(const Vector3d &u, const Vector3d &v);
    static float module(Vector3d &v);
    static float moduleSqr(Vector3d &v);

};



#endif //RAYTRACER_VECTOR_H
