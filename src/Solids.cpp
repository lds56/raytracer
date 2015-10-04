//
// Created by Rui Chen on 9/15/15.
//

#include "Solids.h"
#include <vector>

using namespace std;

Point3d Solid::getIntersection(RayPtr rPtr) {
    Utils::logError("Not implemented yet!");
    exit(1);
}

/*
 * Reference:
 * Intersection of a Line and a Cone
 * David Eberly
 * Geometric Tools, LLC
 * http://www.geometrictools.com/
 *       Copyright c 1998-2015. All Rights Reserved.
 */

Point3d Cone::getIntersection(RayPtr rPtr) {
    float tanThetaSqr = (baseRadius - apexRadius)*(baseRadius - apexRadius)/
                        ((baseCenter - apexCenter).lengthSqr());
    float cosThetaSqr = 1/(tanThetaSqr + 1);
    Matrix<float> V = apexPoint.toMatrix();
    Matrix<float> D = axle.toMatrix();
    Matrix<float> M = D*D.transpose() - DiagonalMatrix<float>(3, vector<float>(3, cosThetaSqr), 0.0f);
    Matrix<float> P = rPtr->getOrigin().toMatrix();
    Matrix<float> U = rPtr->getDirection().toMatrix();
    Matrix<float> delta = P - V;
    float c2 = (U.transpose() * M * U).toNumber();
    float c1 = (U.transpose() * M * delta).toNumber();
    float c0 = (delta.transpose() * M * delta).toNumber();
    float dt = c1 * c1 - c0 * c2;
    if (dt < 0) return Point3d::getNullPoint();
    float t1 = (-c1 - sqrtf(dt))/c2;
    float t2 = (-c1 + sqrtf(dt))/c2;
    if (t1 < 0 && t2 < 0) return Point3d::getNullPoint();
    else if (t1 < 0 && t2 > 0) return rPtr->shootAt(t2);
    else if (t1 > 0 && t2 > 0) return rPtr->shootAt(t1);
    else {
        Utils::logError("Impossible case for t1 and t2!");
        exit(1);
    }
    // TODO: consider the constraint of h (Cone)
}

/*
 * Joseph M. Cychosz and Warren N. Waggenspack, Jr.,
 * Intersecting a Ray with a Cylinder, Graphics Gems IV, pp. 356-365
 *
 */
Point3d Cylinder ::getIntersection(RayPtr rPtr) {
    Point3d rayOrigin = rPtr->getOrigin();
    Vector3d rayDir = rPtr->getDirection();
    Vector3d D = Vector3d::crossProduct(rayDir, axle);
    float d = Vector3d::dotProduct(D.norm(), rayOrigin - apexPoint);
    if (d > apexRadius) return Point3d::getNullPoint();
    float t = Vector3d::dotProduct(Vector3d::crossProduct(axle, rayOrigin - apexCenter), D) /
            D.lengthSqr();
    float k = sqrtf(apexRadius*apexRadius - d*d);
    Vector3d O = Vector3d::crossProduct(D, axle).norm();
    float s = k / (Vector3d::dotProduct(axle, O));
    if (t > s) return Point3d::getNullPoint();
    else return rPtr->shootAt(t - s);
    // TODO: consider the constraint of h (Cylinder)
}

Point3d Sphere :: getIntersection(RayPtr rPtr) {
    Point3d rayOrigin = rPtr->getOrigin();
    Vector3d rayDir = rPtr->getDirection();
    float distanceSqr = Point3d::EuDistanceSqr(rayOrigin, center);
    float projectLen = Vector3d::dotProduct(center - rayOrigin, rayDir);
    if (distanceSqr > radius*radius && projectLen > 0)
            return Point3d::getNullPoint();

    float cosTheta = rayDir.cosThetaWith(center - rayOrigin);
    float deltaSqr = radius*radius - distanceSqr * (1 - cosTheta*cosTheta);

    if (distanceSqr > radius*radius) { // origin is out of circle
        if (deltaSqr < 0) return Point3d::getNullPoint();
        else return rPtr->shootAt(projectLen - sqrtf(deltaSqr));
    } else {                           // origin is in the circle
        return rPtr->shootAt(projectLen + sqrtf(deltaSqr));
    }
}