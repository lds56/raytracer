#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <vector>
#include "bart/parse.h"
#include "definition.h"
#include "Camera.h"
#include "Light.h"
#include "Material.h"
#include "Primitive.h"
#include "Texture.h"

using namespace std;

class Scene {
private:
    CameraPtr cameraPtr;
    Color backgroundColor;
    AmbientLightPtr ambientLightPtr;

    vector<LightPtr> lights;
    vector<MaterialPtr> materials;
    vector<TexturePtr> textures;

public:
    int loadFrom(char* fileName);
    vector<Point3d> loadPonitsFrom(char* fileName);
    vector<Vector3d> loadVectorsFrom(char* fileName);
    int frameNum2;

    void setCamera(CameraPtr cPtr) {this->cameraPtr = cPtr;}
    void setBackground(Color bgcolor) {this->backgroundColor = bgcolor;}
    void setAmbientLight(AmbientLightPtr alPtr) {this->ambientLightPtr = alPtr;}
    void addLight(LightPtr lPtr) {this->lights.push_back(lPtr);}
    void addMaterial(MaterialPtr mPtr) {this->materials.push_back(mPtr);}
    void addPrimitive(PrimitivePtr pPtr);
    void addPrimitive(PrimitivePtr pPtr, MaterialPtr mPtr);
    TexturePtr getTexture(string textureName);
    MaterialPtr getLastMaterial();
};

#endif