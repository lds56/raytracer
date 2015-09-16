//
// Created by Rui Chen on 9/14/15.
//

#include <iostream>
#include "Scene.h"

int Scene ::loadFrom(char* fileName) {
    FILE * file;
    if (!(file = fopen(fileName, "r"))) {
        printf("File %s not found.\n", fileName);
        return 1;
    }

    viParseFile(file, &this);
}

TexturePtr Scene :: getTexture(string textureName) {
    vector<TexturePtr>::iterator iter;
    for (iter = textures.begin(); iter!=textures.end(); ++iter) {
        if (textureName == (*iter)->getTextureName()) {
            return *iter;
        }
    }

    if (iter == textures.end()) {
        TexturePtr newTexturePtr = new TexturePtr(textureName);
        textures.push_back(newTexturePtr);
        return newTexturePtr;
    }
}

void Scene :: addPrimitive(PrimitivePtr pPtr, MaterialPtr mPtr) {
    pPtr->setMaterial(mPtr);
    addPrimitive(pPtr);
}

MaterialPtr Scene :: getLastMaterial() {
    if (materials.empty()) {
        cout << "ERROR: Empty material list" << endl;
        exit(1);
    }
    return materials.back();
}