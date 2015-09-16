//
// Created by Rui Chen on 9/14/15.
//

#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H

class Color {
public:
    float r;
    float g;
    float b;
    Color(float r, float g, float b): r(r), g(g), b(b) {}
    Color(float rgb[3]): r(rgb[0]), g(rgb[1]), b(rgb[2]) {}

    Color(unsigned char r, unsigned char g, unsigned char b):
            Color(r/255.0f, g/255.0f, b/255.0f) {}
    Color(unsigned char rgb[3]):
            Color(rgb[0]/255.0f, rgb[1]/255.0f, rgb[2]/255.0f) {}

    inline Color& operator =(const Color &color);
    inline Color operator +(const Color color) const;
    inline Color operator +=(const Color color);

//    inline Color operator *(const Color color) const;
//    inline Color operator *=(const Color color);

    inline Color operator *(const float scalar) const;
    inline Color operator *=(const float scalar);

};

#endif //RAYTRACER_COLOR_H
