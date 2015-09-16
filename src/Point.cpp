//
// Created by Rui Chen on 9/15/15.
//

#include "Point.h"

inline Point2d& Point2d::operator =(const Point2d &point) {
    if (this == &point) {
        return *this;
    }

    x = point.x;
    y = point.y;

    return *this;
}


inline Vector2d Point2d::operator -(const Point2d &point) const {
    return Vector2d(x - point.x, y - point.y);
}


inline Point2d Point2d::operator +(const Vector2d &vector) const {
    return Point2d(x + vector.x, y + vector.y);
}


inline Point2d Point2d::operator -(const Vector2d &vector) const {
    return Point2d(x - vector.x, y - vector.y);
}


inline Point2d& Point2d::operator +=(const Vector2d &vector) {
    x += vector.x;
    y += vector.y;

    return *this;
}


inline Point2d& Point2d::operator -=(const Vector2d &vector) {
    x -= vector.x;
    y -= vector.y;

    return *this;
}


/*----------2-3d----------*/

inline Point3d& Point3d::operator =(const Point3d &point) {
    if (this == &point) {
        return *this;
    }

    x = point.x;
    y = point.y;
    z = point.z;

    return *this;
}


inline Vector3d Point3d::operator -(const Point3d &point) const {
    return Vector3d(x - point.x, y - point.y, z - point.z);
}


inline Point3d Point3d::operator +(const Vector3d &vector) const {
    return Point3d(x + vector.x, y + vector.y, z + vector.z);
}


inline Point3d Point3d::operator -(const Vector3d &vector) const {
    return Point3d(x - vector.x, y - vector.y, z - vector.z);
}


inline Point3d& Point3d::operator +=(const Vector3d &vector) {
    x += vector.x;
    y += vector.y;
    z += vector.z;

    return *this;
}


inline Point3d& Point3d::operator -=(const Vector3d &vector) {
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;

    return *this;
}


inline Point3d Point3d::operator *(const float scalar) const {
    return Point3d(x * scalar, y * scalar, z * scalar);
}


inline Point3d& Point3d::operator *=(const float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}

