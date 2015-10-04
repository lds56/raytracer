//
// Created by Rui Chen on 9/16/15.
//

#ifndef RAYTRACER_TRIANGLEMESH_H
#define RAYTRACER_TRIANGLEMESH_H

#include "Primitive.h"
#include "Definition.h"
#include "Point.h"
#include "BoundingVolume.h"
#include <vector>

using namespace std;

class TriangleMesh : public Primitive {
public:

    TriangleMesh(int pointNum, Vec3f* pointsArray,
                 int normalNum, Vec3f* normalsArray,
                 int textCoordNum, Vec2f* textCoordsArray,
                 int triangleNum, int * indices):
            pointNum(pointNum), normalNum(normalNum),
            textCoordNum(textCoordNum), triangleNum(triangleNum) {

        points = vector<Point3d>(pointNum);
        for (int i=0; i<pointNum; i++)
            points.push_back(Point3d(pointsArray[i]));
        pointIndice = vector<unsigned short>(triangleNum);

        if (normalNum == 0) {
            normals = vector<Vector3d>(normalNum);
            for (int i=0; i<normalNum; i++)
                normals.push_back(Vector3d(normalsArray[i]));
            normIndice = vector<unsigned short>(triangleNum);
        }

        if (textCoordNum == 0) {
            textCoords = vector<Point2d>(textCoordNum);
            for (int i=0; i<textCoordNum; i++)
                textCoords.push_back(Point2d(textCoordsArray[i]));
            textIndice = vector<unsigned short>(triangleNum);
        }

        /* indices appear in this order: [texture] [normals] vertices. []=optional */
        for (int i=0; i<triangleNum; i++) {
            if (indices[i*3] != -1)
                textIndice.push_back((unsigned short)indices[i*3]);
            if (indices[i*3+1] != -1)
                normIndice.push_back((unsigned short)indices[i*3+1]);
            pointIndice[i] = (unsigned short)indices[i*3+2];
        }

    }

    TriangleMesh(vector<Point3d> points,
                 vector<Vector3d> normals, vector<Point2d> textCoords):
            points(points), normals(normals), textCoords(textCoords) {}

    void initialize();
    void buildBoundingVolume();

private:
    int pointNum, normalNum, textCoordNum, triangleNum;
    vector<Point3d> points;
    vector<Vector3d> normals;
    vector<Point2d> textCoords;
    vector<unsigned short> textIndice;
    vector<unsigned short> normIndice;
    vector<unsigned short> pointIndice;


};

#endif //RAYTRACER_TRIANGLEMESH_H
