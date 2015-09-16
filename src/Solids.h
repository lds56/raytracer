//
// Created by Rui Chen on 9/15/15.
//

#ifndef RAYTRACER_SOLID_H
#define RAYTRACER_SOLID_H

#include "Primitive.h"
#include "Point.h"

class Solid : public Primitive {
public:
    Solid(): Primitive() {}
};

class Cone : public Solid {
public:
    Cone(): Solid(), apexCenter(Point3d::NullPoint),
            baseCenter(Point3d::NullPoint), apexRadius(-1), baseRadius(-1) {}
    Cone(Point3d apexCenter, Point3d baseCenter,
         float apexRadius, float baseRadius):
            apexCenter(apexCenter), baseCenter(baseCenter),
            apexRadius(apexRadius), baseRadius(baseRadius) {}
private:
    Point3d apexCenter, baseCenter;
    float apexRadius, baseRadius;
};

class Cylinder : public Cone {
public:
    Cylinder(Point3d apexCenter, Point3d baseCenter,
             float baseRadius): Cone(apexCenter, baseCenter, baseRadius, 0) {}

private:
};


class Sphere : public Solid {
public:
    Sphere(Point3d center, float radius): center(center), radius(radius) {}
private:
    Point3d center;
    float radius;
};

#endif //RAYTRACER_SOLID_H
