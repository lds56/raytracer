//
// Created by Rui Chen on 9/19/15.
//

#ifndef RAYTRACER_LDS_H
#define RAYTRACER_LDS_H

#include "Scene.h"

class Screen {
public:
    Screen(ScenePtr sPtr): size(sPtr->getViewpoint()->getSize()),
                           pixels(new Color[size.width * size.height]),
                           scenePtr(sPtr) {}

    ~Screen() {delete[] pixels;}

    void traceRay();
    void traceRayAt(float frameTime);
    //void saveAsPPM(string outputName);
    //void saveAsPng(string outputName);

private:
    Size size;
    Color* pixels;
    ScenePtr scenePtr;

};

#endif //RAYTRACER_LDS_H
