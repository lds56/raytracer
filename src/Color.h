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
    float a;

    Color() {Color(0.0f, 0.0f, 0.0f, 1.0f);}

    Color(float r, float g, float b) { Color(r, g, b, 1.0f); }
    Color(float r, float g, float b, float a): r(r), g(g), b(b), a(a) {}

    Color(float rgb[3]) { Color(rgb[0], rgb[1], rgb[2]); }
    Color(float rgb[3], float a) { Color(rgb[0], rgb[1], rgb[2], 1.0f); }

    Color(unsigned char r, unsigned char g, unsigned char b):
            Color(r/255.0f, g/255.0f, b/255.0f) {}
    Color(unsigned char rgb[3]):
            Color(rgb[0]/255.0f, rgb[1]/255.0f, rgb[2]/255.0f) {}

    Color& operator=(const Color &color);
    Color operator+(const Color color) const;
    Color operator+=(const Color color);

//    inline Color operator *(const Color color) const;
//    inline Color operator *=(const Color color);

    Color operator*(const float scalar) const;
    Color operator*=(const float scalar);

    const static Color noColor;

};

#endif //RAYTRACER_COLOR_H
