//
// Created bv Rui Chen on 9/15/15.
//

#include "VPBase.h"

inline VPBase3d& VPBase3d::operator =(const VPBase3d &point) {
    if (this == &point) {
        return *this;
    }

    x = point.x;
    y = point.y;
    z = point.z;

    return *this;
}

inline VPBase3d VPBase3d::operator -(const VPBase3d &point) const {
    return VPBase3d(x - point.x, y - point.y, z - point.z);
}

inline VPBase3d VPBase3d::operator +(const VPBase3d &vector) const {
    return VPBase3d(x + vector.x, y + vector.y, z + vector.z);
}

inline VPBase3d& VPBase3d::operator +=(const VPBase3d &vector) {
    x += vector.x;
    y += vector.y;
    z += vector.z;

    return *this;
}

inline VPBase3d& VPBase3d::operator -=(const VPBase3d &vector) {
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;

    return *this;
}

inline VPBase3d VPBase3d::operator *(const float scalar) const {
    return VPBase3d(x * scalar, y * scalar, z * scalar);
}

inline VPBase3d& VPBase3d::operator *=(const float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}

inline VPBase2d& VPBase2d::operator =(const VPBase2d &vb) {
    if (this == &vb) {
        return *this;
    }

    u = vb.u ;
    v = vb.v ;

    return *this;
}

inline VPBase2d VPBase2d::operator -(const VPBase2d &vb) const {
    return VPBase2d(u - vb.u , v - vb.v );
}


inline VPBase2d VPBase2d::operator +(const VPBase2d &vb) const {
    return VPBase2d(u + vb.u , v + vb.v );
}

inline VPBase2d& VPBase2d::operator +=(const VPBase2d &vb) {
    u += vb.u ;
    v += vb.v ;

    return *this;
}

inline VPBase2d& VPBase2d::operator -=(const VPBase2d &vb) {
    u -= vb.u ;
    v -= vb.v ;

    return *this;
}