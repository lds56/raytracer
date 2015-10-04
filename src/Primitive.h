//
// Created by Rui Chen on 9/14/15.
//

#ifndef RAYTRACER_PRIMITIVE_H
#define RAYTRACER_PRIMITIVE_H

#include "Material.h"
#include "Texture.h"
#include "Definition.h"
#include "Point.h"

class Primitive {
public:
    Primitive(): materialPtr(NULL), texturePtr(NULL) {}
    Primitive(MaterialPtr materialPtr): materialPtr(materialPtr) {}

    virtual ~Primitive() {}

    void setMaterial(MaterialPtr materialPtr) {this->materialPtr = materialPtr;}
    void setTexture(TexturePtr texturePtr) {this->texturePtr = texturePtr;}

    virtual Point3d getIntersection(RayPtr rPtr);

    virtual void buildBoundingVolume();
    //virtual int intersect()

protected:
    MaterialPtr materialPtr;
    TexturePtr texturePtr;
    BoundingVolumePtr bvPtr;

};

#endif //RAYTRACER_PRIMITIVE_H
