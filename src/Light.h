//
// Created by Rui Chen on 9/14/15.
//

#ifndef RAYTRACER_LIGHT_H
#define RAYTRACER_LIGHT_H

#include "Color.h"
#include "Point.h"

class Light {
public:
    Light(Color color): color(color) {}
    ~Light() {delete this;}

private:
    Color color;
};

class PointLight : public Light {
public:
    PointLight(Color color, Point3d fromP): Light(color), fromP(fromP) {}
    ~PointLight() {}

private:
    Point3d fromP;
};

class AmbientLight : public Light {
public:
    AmbientLight(Color color): Light(color) {}
};

#endif //RAYTRACER_LIGHT_H
