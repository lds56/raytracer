//
// Created by Rui Chen on 9/14/15.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H

#include "Color.h"
#include "Definition.h"
#include <string>

using namespace std;

class Material {
public:
    string name;
    float attenuation, refraction, shine;
    Color ambience, diffuse, specular, transmission;

    Material(string name,
             float attenuation, float refraction, float shine,
             Color ambience, Color diffuse, Color specular, Color transmission
    ): name(name), attenuation(attenuation),
       refraction(refraction), shine(shine),
       ambience(ambience), diffuse(diffuse),
       specular(specular), transmission(transmission) {};

    ~Material() {}
};

#endif //RAYTRACER_MATERIAL_H
