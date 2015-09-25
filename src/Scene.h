#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <vector>
#include "bart/parse.h"
#include "Definition.h"
#include "Viewpoint.h"
#include "Light.h"
#include "Material.h"
#include "Primitive.h"
#include "Texture.h"

using namespace std;

class Scene {
private:
    ViewpointPtr viewpointPtr;
    Color bgColor;
    AmbientLightPtr ambientLightPtr;

    float animStart, animEnd;
    int frameNum;

    vector<LightPtr> lights;
    vector<MaterialPtr> materials;
    vector<TexturePtr> textures;

    vector<PrimitivePtr> primitives;
    vector<TriangleMeshPtr> meshes;
    vector<PrimCollePtr> primcolles;

public:
    Scene(char* fileName):
            viewpointPtr(NULL), bgColor(Color::noColor),
            ambientLightPtr(new AmbientLight(Color::noColor)) {
        loadFrom(fileName);
    }

    ~Scene() {}

    int loadFrom(char* fileName);
    void buildNodetree(float time);

    void setViewpoint(ViewpointPtr vpPtr) {this->viewpointPtr = vpPtr;}
    void setBackground(Color bgcolor) {this->bgColor = bgcolor;}
    void setAmbientLight(AmbientLightPtr alPtr) {this->ambientLightPtr = alPtr;}
    void setAnimParams(float animStart, float animEnd, int frameNum);

    void addLight(LightPtr lPtr) {this->lights.push_back(lPtr);}
    void addMaterial(MaterialPtr mPtr) {this->materials.push_back(mPtr);}
    void addPrimitive(PrimitivePtr pPtr);
    void addPrimitive(PrimitivePtr pPtr, MaterialPtr mPtr);
    void addPrimitive(PrimitivePtr pPtr, TexturePtr tPtr);
    void addPrimColle(PrimCollePtr pcPtr) {this->primcolles.push_back(pcPtr);}
    void addMesh(TriangleMeshPtr meshPtr) {this->meshes.push_back(meshPtr);}

    TexturePtr getTexture(string textureName);
    MaterialPtr getLastMaterial();
    ViewpointPtr getViewpoint() { return viewpointPtr; }
    int getFrameNum() { return frameNum; }
    float getFrameDuration() { return (animEnd - animStart) / (frameNum - 1); }
};


#endif