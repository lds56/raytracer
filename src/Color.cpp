//
// Created by Rui Chen on 9/14/15.
//

#include "Color.h"

inline Color& Color::operator =(const Color &color) {
    if (this == &color) {
        return *this;
    }

    r = color.r;
    g = color.g;
    b = color.b;

    return *this;
}


inline Color Color::operator +(const Color color) const {
    Color result = *this;
    result += color;

    return result;
}


inline Color Color::operator +=(const Color color) {
    r += color.r;
    g += color.g;
    b += color.b;

    return *this;
}

//
//inline Color Color::operator *(const Color color) const {
//    Color result = *this;
//    result *= color;
//
//    return result;
//}
//
//
//inline Color Color::operator *=(const Color color) {
//    r *= color.r;
//    g *= color.g;
//    b *= color.b;
//
//    return *this;
//}


inline Color Color::operator *(const float scalar) const {
    Color result = *this;
    result *= scalar;

    return result;
}


inline Color Color::operator *=(const float scalar) {
    r *= scalar;
    g *= scalar;
    b *= scalar;

    return *this;
}