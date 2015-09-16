//
// Created by Rui Chen on 9/14/15.
//

#ifndef RAYTRACER_DEFINITION_H
#define RAYTRACER_DEFINITION_H

#include "Primitive.h"
#include "Scene.h"
#include "Camera.h"
#include "Planes.h"
#include "Solids.h"
#include "Texture.h"
#include "Light.h"
#include <memory>

using namespace std;

// const static string RESOURCE_PATH = string("resource")

typedef float Vec2f[2];
typedef float Vec3f[3];
typedef float Vec4f[4];

typedef shared_ptr<Scene> ScenePtr;
typedef shared_ptr<Camera> CameraPtr;
typedef shared_ptr<Light> LightPtr;
typedef shared_ptr<AmbientLight> AmbientLightPtr;
typedef shared_ptr<Material> MaterialPtr;
typedef shared_ptr<Texture> TexturePtr;

typedef shared_ptr<Primitive> PrimitivePtr;
typedef shared_ptr<Plane> PlanePtr;
typedef shared_ptr<Solid> SolidPtr;

#endif //RAYTRACER_DEFINITION_H
