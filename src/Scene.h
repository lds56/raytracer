#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <vector>
#include "bart/parse.h"
#include "Definition.h"
#include "Camera.h"
#include "Light.h"
#include "Material.h"
#include "Primitive.h"
#include "Texture.h"

using namespace std;

class Scene {
private:
    CameraPtr cameraPtr;
    Color bgColor;
    AmbientLightPtr ambientLightPtr;

    vector<LightPtr> lights;
    vector<MaterialPtr> materials;
    vector<TexturePtr> textures;

    vector<PrimitivePtr> primitives;
    vector<TriangleMeshPtr> meshes;

public:
    Scene(char* fileName):
            cameraPtr(NULL), bgColor(Color::noColor),
            ambientLightPtr(new AmbientLight(Color::noColor)) {
        loadFrom(fileName);
    }

    int loadFrom(char* fileName);

    void setCamera(CameraPtr cPtr) {this->cameraPtr = cPtr;}
    void setBackground(Color bgcolor) {this->bgColor = bgcolor;}
    void setAmbientLight(AmbientLightPtr alPtr) {this->ambientLightPtr = alPtr;}

    void addLight(LightPtr lPtr) {this->lights.push_back(lPtr);}
    void addMaterial(MaterialPtr mPtr) {this->materials.push_back(mPtr);}
    void addPrimitive(PrimitivePtr pPtr);
    void addPrimitive(PrimitivePtr pPtr, MaterialPtr mPtr);
    void addPrimitive(PrimitivePtr pPtr, TexturePtr tPtr);
    void addMesh(TriangleMeshPtr meshPtr) {this->meshes.push_back(meshPtr);}

    TexturePtr getTexture(string textureName);
    MaterialPtr getLastMaterial();
};


#endif