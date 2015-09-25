//
// Created by Rui Chen on 9/14/15.
//

#ifndef RAYTRACER_PRIMITIVE_H
#define RAYTRACER_PRIMITIVE_H

#include "Material.h"
#include "Texture.h"

class Primitive {
public:
    Primitive(): materialPtr(NULL), texturePtr(NULL) {}
    Primitive(MaterialPtr materialPtr): materialPtr(materialPtr) {}

    virtual ~Primitive() {}

    void setMaterial(MaterialPtr materialPtr) {this->materialPtr = materialPtr;}
    void setTexture(TexturePtr texturePtr) {this->texturePtr = texturePtr;}

    virtual bool isIntersected(RayPtr rPtr);

    virtual void buildBoVo();
    //virtual int intersect()

private:
    MaterialPtr materialPtr;
    TexturePtr texturePtr;

};

#endif //RAYTRACER_PRIMITIVE_H
