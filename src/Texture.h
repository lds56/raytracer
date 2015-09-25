//
// Created by Rui Chen on 9/16/15.
//

#ifndef RAYTRACER_TEXTURE_H
#define RAYTRACER_TEXTURE_H

#include "Color.h"
#include "Definition.h"
#include <string>

using namespace std;

class Texture {
public:

    Texture(): colors(NULL) {}

    Texture(char textureName[100]): colors(NULL) {
        Texture(string(textureName));
    }

    Texture(string textureName):
            textureName(string(textureName)), colors(NULL) {
        loadTexture(textureName);
    }

    ~Texture() {if (colors) delete[] colors;}

    inline string getTextureName() { return textureName; }

private:
    int height, width;
    Color* colors; // value < 1.0
    string textureName;

    void loadTexture(string texturePath);
    void eatComments(FILE* f);
    void eatWhitespace(FILE* f);

};

#endif //RAYTRACER_TEXTURE_H
