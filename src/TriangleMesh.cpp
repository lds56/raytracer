//
// Created by Rui Chen on 9/16/15.
//

#include "TriangleMesh.h"

void TriangleMesh::buildBoundingVolume() {
    Point3d maxExtent = points[0];
    Point3d minExtent = points[0];
    for (vector<Point3d>::iterator iter=points.begin();
            iter!=points.end(); iter++) {
        maxExtent = Point3d::pointMax(maxExtent, *iter);
        minExtent = Point3d::pointMin(minExtent, *iter);
    }

    bvPtr = BoundingVolumePtr(new BoundingVolume(minExtent, maxExtent));
}

void TriangleMesh::initialize() {

}