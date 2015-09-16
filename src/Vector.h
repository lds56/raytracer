//
// Created by Rui Chen on 9/14/15.
//

#ifndef RAYTRACER_VECTOR_H
#define RAYTRACER_VECTOR_H

#include <cstdio>
#include "definition.h"

class Vector2d {
public:
    float x, y;

    Vector2d() {}
    Vector2d(float x, float y): x(x), y(y) {}
    Vector2d(Vec2f pos): x(pos[0]), y(pos[1]) {}

    inline Vector2d operator =(const Vector2d &vector);

    inline Vector2d operator +(const Vector2d &vector) const;
    inline Vector2d operator -(const Vector2d &vector) const;
    inline Vector2d operator +=(const Vector2d &vector);
    inline Vector2d operator -=(const Vector2d &vector);

    inline Vector2d operator *(const float scalar) const;
    inline Vector2d operator /(const float scalar) const;
    inline Vector2d operator *=(const float scalar);
    inline Vector2d operator /=(const float scalar);

    inline float length() const;
    inline float lengthSqr() const;
    inline float normalize();
    inline Vector2d negate();
};


inline bool operator ==(const Vector2d &vectorA, const Vector2d &vectorB) {
    return (vectorA.x == vectorB.x &&
            vectorA.y == vectorB.y);
}


inline Vector2d operator -(const Vector2d &vector) {
    return Vector2d(-vector.x, -vector.y);
}


inline float dotProduct(const Vector2d &u, const Vector2d &v) {
    return (u.x * v.x) +
           (u.y * v.y);
}

class Vector3d {
public:
    float x, y, z;

    Vector3d() {}
    Vector3d(Vec3f pos): x(pos[0]), y(pos[1]), z(pos[2]) {}
    Vector3d(const float x, const float y, const float z):
            x(x), y(y), z(z) {}

    inline Vector3d operator =(const Vector3d &vector);

    inline Vector3d operator +(const Vector3d &vector) const;
    inline Vector3d operator -(const Vector3d &vector) const;
    inline Vector3d operator +=(const Vector3d &vector);
    inline Vector3d operator -=(const Vector3d &vector);

    inline Vector3d operator *(const float scalar) const;
    inline Vector3d operator /(const float scalar) const;
    inline Vector3d operator *=(const float scalar);
    inline Vector3d operator /=(const float scalar);

    inline float boxArea() const;
    inline int dominantIndex() const;
    inline Vector2d dropIndex(const int index) const;
    inline float length() const;
    inline float lengthSqr() const;
    inline float normalize();
    inline Vector3d norm();
    inline Vector3d negate();

    void print(char * id) const {
        printf("Vector %s: %f, %f, %f\n", id, x, y, z);
    }
};


inline bool operator ==(const Vector3d &vectorA, const Vector3d &vectorB) {
    return (vectorA.x == vectorB.x &&
            vectorA.y == vectorB.y &&
            vectorA.z == vectorB.z);
}


inline Vector3d operator -(const Vector3d &vector) {
    return Vector3d(-vector.x, -vector.y, -vector.z);
}


inline Vector3d crossProduct(const Vector3d &u, const Vector3d &v) {
    return Vector3d(u.y * v.z - u.z * v.y,
                    u.z * v.x - u.x * v.z,
                    u.x * v.y - u.y * v.x);
}


inline float dotProduct(const Vector3d &u, const Vector3d &v) {
    return (u.x * v.x) +
           (u.y * v.y) +
           (u.z * v.z);
}


#endif //RAYTRACER_VECTOR_H
