//
// Created by Rui Chen on 9/20/15.
//

#ifndef RAYTRACER_BOUNDINGVOLUME_H
#define RAYTRACER_BOUNDINGVOLUME_H

#include "Point.h"
#include "Definition.h"

class BoundingVolume {
public:
    BoundingVolume(Point3d minCorner, Point3d maxCorner):
            minCorner(minCorner - borderVector),
            maxCorner(maxCorner + borderVector) {}

    BoundingVolume(float minX, float minY, float minZ,
                   float maxX, float maxY, float maxZ) {
        BoundingVolume(Point3d(minX, minY, minZ), Point3d(maxX, maxY, maxZ));
    }

    inline Point3d getCentroid() { return (minCorner + maxCorner) * 0.5f; }

    Point3d getMinCorner() {return minCorner;}
    Point3d getMaxCorner() {return maxCorner;}

private:
    Point3d minCorner, maxCorner;
    static const Vector3d borderVector;
};

#endif //RAYTRACER_BOUNDINGVOLUME_H
