//
// Created by Rui Chen on 9/15/15.
//

#ifndef RAYTRACER_VPBase_H
#define RAYTRACER_VPBase_H

class VPBase3d {
public:
    float x;
    float y;
    float z;
    
    VPBase3d(float x, float y, float z): x(x), y(y), z(z) {}
    VPBase3d(float pos[3]): x(pos[0]), y(pos[1]), z(pos[2]) {}
    
    ~VPBase3d() {delete this;}
    
    inline VPBase3d& operator =(const VPBase3d &vb);
    inline VPBase3d operator -(const VPBase3d &vb) const;
    inline VPBase3d operator +(const VPBase3d &vb) const;

    inline VPBase3d& operator +=(const VPBase3d &vb);
    inline VPBase3d& operator -=(const VPBase3d &vb);

    inline VPBase3d operator *(const float scalar) const;
    inline VPBase3d& operator *=(const float scalar);
};

class VPBase2d {
public:
    float u;
    float v;

    VPBase2d(float u, float v): u(u), v(v) {}
    VPBase2d(float pos[2]): u(pos[0]), v(pos[1]) {}

    ~VPBase2d() {delete this;}

    inline VPBase2d& operator =(const VPBase2d &vb);
    inline VPBase2d operator -(const VPBase2d &vb) const;
    inline VPBase2d operator +(const VPBase2d &vb) const;

    inline VPBase2d& operator +=(const VPBase2d &vb);
    inline VPBase2d& operator -=(const VPBase2d &vb);

    inline VPBase2d operator *(const float scalar) const;
    inline VPBase2d& operator *=(const float scalar);
};

#endif //RAYTRACER_VPBase_H
