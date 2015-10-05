//
// Created by Rui Chen on 9/14/15.
//

#ifndef RAYTRACER_DEFINITION_H
#define RAYTRACER_DEFINITION_H

#include <memory>

using namespace std;

// const static string RESOURCE_PATH = string("resource")

typedef float Vec2f[2];
typedef float Vec3f[3];
typedef float Vec4f[4];

class Scene;
class Viewpoint;
class Material;
class Light;
class AmbientLight;
class Texture;
class Primitive;
class PrimColle;
class Plane;
class Solid;
class TriangleMesh;
class Ray;
class BoundingVolume;

class Point3d;
class Point2d;
class Vector3d;
class Vector2d;

struct Size {
    Size(int h, int w): height(h), width(w) {}
    int height;
    int width;
};

typedef shared_ptr<Scene> ScenePtr;
typedef shared_ptr<Viewpoint> ViewpointPtr;
typedef shared_ptr<Light> LightPtr;
typedef shared_ptr<AmbientLight> AmbientLightPtr;
typedef shared_ptr<Material> MaterialPtr;
typedef shared_ptr<Texture> TexturePtr;
typedef shared_ptr<Ray> RayPtr;
typedef shared_ptr<BoundingVolume> BoundingVolumePtr;

typedef shared_ptr<Primitive> PrimitivePtr;
typedef shared_ptr<PrimColle> PrimCollePtr;
typedef shared_ptr<Plane> PlanePtr;
typedef shared_ptr<Solid> SolidPtr;
typedef shared_ptr<TriangleMesh> TriangleMeshPtr;


#endif //RAYTRACER_DEFINITION_H
