//
// Created by Rui Chen on 9/20/15.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "Material.h"
#include "Point.h"
#include "Utils.h"

class Ray {
public:
    Ray() {}
    Ray(Point3d origin, Vector3d direction, MaterialPtr medium):
            origin(origin), direction(direction), medium(medium) {
        invDirection = Vector3d(Utils :: fInverse(direction.x),
                                Utils :: fInverse(direction.y),
                                Utils :: fInverse(direction.z));
    }
    inline bool isOrthogonal(Vector3d v) {
        return Utils::fIsZero(Vector3d::dotProduct(direction, v));
    }
    Point3d getOrigin() {return origin;}
    Vector3d getDirection() {return direction;}
    Point3d shootAt(float k) {return origin + k*direction;}

private:
    MaterialPtr medium;
    Point3d origin;
    Vector3d direction, invDirection;
};

#endif //RAYTRACER_RAY_H
