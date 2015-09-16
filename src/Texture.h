//
// Created by Rui Chen on 9/16/15.
//

#ifndef RAYTRACER_TEXTURE_H
#define RAYTRACER_TEXTURE_H

#include "Color.h"
#include <string>

using namespace std;

class Texture {
public:
    Texture(char textureName[100]):
            textureName(string(textureName)) {
        loadTexture(textureName + string(".ppm"));
    }

    inline string getTextureName() { return textureName; }

private:
    int height, width;
    Color* colors;
    string textureName;

    void loadTexture(string texturePath);
    void eatComments(FILE* f);
    void eatWhitespace(FILE* f);

};

#endif //RAYTRACER_TEXTURE_H
