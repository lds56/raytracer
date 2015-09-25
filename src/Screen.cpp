//
// Created by Rui Chen on 9/19/15.
//

#include "Screen.h"

void Screen :: traceRay() {
    float frameDuration = scenePtr->getFrameDuration();
    for (int i=0; i< scenePtr->getFrameNum(); i++) {
        traceRayAt(i * scenePtr->getFrameNum());
        //saveAsPPM("out.ppm");
    }
}

void Screen ::traceRayAt(float frameTime) {
    //scenePtr->buildNodeTree(frameTime);
}