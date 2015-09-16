//
// Created by Rui Chen on 9/14/15.
//

#ifndef RAYTRACER_PRIMITIVE_H
#define RAYTRACER_PRIMITIVE_H

#include <stddef.h>
#include "Material.h"
#include "definition.h"


class Primitive {
public:
    MaterialPtr materialPtr;
    TexturePtr texturePtr;

    Primitive(): materialPtr(NULL), texturePtr(NULL) {}
    Primitive(MaterialPtr materialPtr): materialPtr(materialPtr) {}

    virtual ~Primitive() {}

    void setMaterial(MaterialPtr materialPtr) {this->materialPtr = materialPtr;}
    void setTexture(TexturePtr texturePtr) {this->texturePtr = texturePtr;}

};

#endif //RAYTRACER_PRIMITIVE_H
