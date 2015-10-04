//
// Created by Rui Chen on 9/14/15.
//

#include "Planes.h"
#include "Utils.h"
#include "Ray.h"

Point3d Plane ::getIntersection(RayPtr rPtr){
    if (rPtr->isOrthogonal(aNorm)) return Point3d::getNullPoint();

    float k = Vector3d::dotProduct(aPoint - rPtr->getOrigin(), aNorm) /
              Vector3d::dotProduct(rPtr->getDirection(), aNorm);
    if (Utils::fIsPos(k)) return rPtr->shootAt(k);
    else return Point3d::getNullPoint();
}

Point3d Polygon :: getIntersection(RayPtr rayPtr) {
    Point3d interP = Plane::getIntersection(rayPtr);
    if (interP.isNullPoint()) return Point3d::getNullPoint();
    else {
        for (int i=0; i<vertexNum; i++) // substract offset
            projVertex[i] -= (interP.projectTo(getDomiCoord()) - Point2d(0, 0));
        int crossNum = 0, SHValue = Utils::SHFunc(projVertex[0].v);
        for (int a=0; a<vertexNum; a++) {
            int b = (a + 1) % vertexNum;
            Point2d& pa = projVertex[a];
            Point2d& pb = projVertex[b];
            if (SHValue != Utils::NSHFunc(pb.v)) {
                if ((pa.u > 0 && pb.u > 0))
                //||
                  //  (pa.u > 0 || pb.u > 0) &&
                    //   pa.u - pa.v * (pb.u - pa.u) * Utils::fInverse(pb.v - pa.v))
                    //TODO: Leave something out
                    crossNum++;
            }
            SHValue = Utils::NSHFunc(pb.v);
        }
        for (int i=0; i<vertexNum; i++) // Add back the offset
            projVertex[i] += (interP.projectTo(getDomiCoord()) - Point2d(0, 0));

        if (crossNum%2 == 1) return interP;
        else return Point3d::getNullPoint();
    }

}

void Polygon :: buildBoundingVolume() {
    Point3d maxCorner = vertex[0];
    Point3d minCorner = vertex[0];
    for (int i=1; i<vertexNum; i++) {
        maxCorner = Point3d::pointMax(maxCorner, vertex[i]);
        minCorner = Point3d::pointMin(minCorner, vertex[i]);
    }
    BoundingVolumePtr bvPtr = BoundingVolumePtr(new BoundingVolume(minCorner, maxCorner));
}