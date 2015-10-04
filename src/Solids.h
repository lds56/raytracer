//
// Created by Rui Chen on 9/15/15.
//

#ifndef RAYTRACER_SOLID_H
#define RAYTRACER_SOLID_H

#include "Definition.h"
#include "Primitive.h"
#include "Point.h"
#include "Matrix.h"
#include "Ray.h"

class Solid : public Primitive {
public:
    Solid(): Primitive() {}
    virtual Point3d getIntersection(RayPtr rPtr);
};

class Cone : public Solid {
public:
    Cone(): Solid(), apexCenter(Point3d::NullPoint),
            axle(Vector3d(0, 0, 0)), baseCenter(Point3d::NullPoint),
            apexRadius(-1), baseRadius(-1) {}
    Cone(Point3d apexCenter, Point3d baseCenter,
         float apexRadius, float baseRadius):
            axle((baseCenter - apexCenter).norm()),
            apexCenter(apexCenter), baseCenter(baseCenter),
            apexRadius(apexRadius), baseRadius(baseRadius) {

        if (apexRadius == baseRadius) apexPoint = apexCenter;
        else apexPoint = Point3d((baseCenter*apexRadius - apexCenter*baseRadius) /
                                 (apexRadius - baseRadius));
    }
    Point3d getIntersection(RayPtr rPtr);

protected:
    Vector3d axle;
    Point3d apexCenter, baseCenter, apexPoint;
    float apexRadius, baseRadius;
};

class Cylinder : public Cone {
public:
    Cylinder(Point3d apexCenter, Point3d baseCenter,
             float baseRadius): Cone(apexCenter, baseCenter, baseRadius, baseRadius) {}
    Point3d getIntersection(RayPtr rPtr);

private:
};

class Sphere : public Solid {
public:
    Sphere(Point3d center, float radius): center(center), radius(radius) {}
    Point3d getIntersection(RayPtr rPtr);

private:
    Point3d center;
    float radius;
};

#endif //RAYTRACER_SOLID_H
