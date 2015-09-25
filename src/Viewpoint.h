//
// Created by Rui Chen on 9/14/15.
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "Point.h"
#include "Vector.h"
#include <memory>

using namespace std;

class Viewpoint {
public:
    Size size;
    float angle, aspectRatio, hither;
    Point3d fromP, atP;
    Vector3d upV;

    Viewpoint(int height, int width,
           float angle, float hither,
           Point3d fromP, Point3d atP, Vector3d upV):
            size(Size(height, width)),
            angle(angle), aspectRatio((float)width/(float)height), hither(hither),
            fromP(fromP), atP(atP), upV(upV) {
    }

    Size getSize() {return size;}
};



#endif //RAYTRACER_CAMERA_H
