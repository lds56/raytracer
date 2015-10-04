//
// Created by Rui Chen on 9/14/15.
//

#ifndef RAYTRACER_SHAPES_H
#define RAYTRACER_SHAPES_H

#include "Definition.h"
#include "Primitive.h"
#include "Point.h"
#include "Vector.h"
#include "BoundingVolume.h"
#include <vector>
#include <cmath>

using namespace std;

class Plane : public Primitive {
public:
    Plane() {}
    Plane(Vector3d aNorm, Point3d aPoint):
            aNorm(aNorm), aPoint(aPoint) {
        float ax = fabs(aNorm.x);
        float ay = fabs(aNorm.y);
        float az = fabs(aNorm.z);
        if (ax >= ay && ax >= az) domiCoord = 0;
        else if (ay >= ax && ay >= az) domiCoord = 1;
        else if (az >= ax && az >= ay) domiCoord = 2;
        else domiCoord = -1;
    }

    virtual Point3d getIntersection(RayPtr rPtr);
    int getDomiCoord() {return domiCoord;}

private:
    Vector3d aNorm;
    Point3d aPoint;
    int domiCoord;
};

class Polygon : public Plane {
public:
    Polygon(int vertexNum, Vec3f* vertexArray): vertexNum(vertexNum) {

        vertex = new Point3d[vertexNum];
        for (int i=0; i<vertexNum; i++)
            vertex[i] = Point3d(vertexArray[i]);
        Plane(Vector3d::crossProduct(vertex[1] - vertex[0], vertex[2] - vertex[0]).norm(),
              vertex[0]);

        projVertex = new Point2d[vertexNum];
        for (int i=0; i<vertexNum; i++)
            projVertex[i] = vertex[i].projectTo(getDomiCoord());
    }

    Point3d getIntersection(RayPtr rPtr);

    void buildBoundingVolume();

    ~Polygon() {
        delete[] vertex;
        delete[] projVertex;
    }

private:
    int vertexNum;
    Point3d* vertex;
    Point2d* projVertex; // Projective vertex
};

class PolygonPatch : public Polygon {
public:
    PolygonPatch(int vertexNum, Vec3f* vertexArray, Vec3f* normArray):
            Polygon(vertexNum, vertexArray) {

        norms = new Vector3d[vertexNum];
        for (int i=0; i<vertexNum; i++)
            norms[i] = Vector3d(normArray[i]);
    }
private:
    Vector3d* norms;
};


class TexturedPolygon : public Polygon {
public:
    TexturedPolygon(int vertexNum, Vec3f* vs, Vec2f* ts):
            Polygon(vertexNum, vs) {

        verTexCord = new Point2d[vertexNum];
        for (int i=0; i<vertexNum; i++)
            verTexCord[i] = Point2d(ts[i]);
    }
private:
    Point2d* verTexCord;
};

class TexturedPolygonPatch : public PolygonPatch {
public:
    TexturedPolygonPatch(int vertexNum, Vec3f* vs, Vec3f* ns, Vec2f* ts):
            PolygonPatch(vertexNum, vs, ns) {

        verTexCord = new Point2d[vertexNum];
        for (int i=0; i<vertexNum; i++)
            verTexCord[i] = Point2d(ts[i]);
    }
private:
    Point2d* verTexCord;
};

class Triangle : public Polygon {
public:
    Triangle(Vec3f v[3]): Polygon(3, v) {}

private:
};

class TrianglePatch : public PolygonPatch {
public:
    TrianglePatch(Vec3f vs[3], Vec3f ns[3]): PolygonPatch(3, vs, ns) {}

private:
};

class TexturedTriangle : public TexturedPolygon {
public:
    TexturedTriangle(Vec3f vs[3], Vec2f ts[3]): TexturedPolygon(3, vs, ts) {}

private:
};

class TexturedTrianglePatch : public TexturedPolygonPatch {
public:
    TexturedTrianglePatch(Vec3f vs[3], Vec3f ns[3], Vec2f ts[3]):
            TexturedPolygonPatch(3, vs, ns, ts) {}

private:
};

#endif //RAYTRACER_SHAPES_H
