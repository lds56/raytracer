//
// Created by Rui Chen on 9/19/15.
//

#ifndef RAYTRACER_PRIMITIVECOLLE_H
#define RAYTRACER_PRIMITIVECOLLE_H

#include <vector>
#include <map>
#include "Primitive.h"
#include "Definition.h"

using namespace std;

//typedef vector<PrimitivePtr> PrimPtrs;
typedef pair<float, PrimitivePtr> PrimColleEl;

class PrimColle {
public:
    PrimColle(): currentFrame(0) {}

    void addFrame(int frameTime, PrimitivePtr pPtr) {
//        if (frameMap.count(frameTime) == 0)
//           frameMap.insert(PrimColleEl(frameTime, PrimPtrs{pPtr}));
//        else frameMap.at(frameTime).push_back(pPtr);
        frameMap.insert(PrimColleEl(frameTime, pPtr));
    }
    void addFrame(int frameTime, PrimitivePtr pPtr, MaterialPtr mPtr) {
        pPtr->setMaterial(mPtr);
        addFrame(frameTime, pPtr);
    }
    PrimitivePtr getPrimitiveAt(int frameTime) {
        return frameMap[frameTime];
    }

    ~PrimColle() {}

private:
    unsigned int currentFrame;
    map<float, PrimitivePtr> frameMap;
};

#endif //RAYTRACER_PRIMITIVECOLLE_H
