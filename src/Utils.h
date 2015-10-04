//
// Created by Rui Chen on 9/18/15.
//

#ifndef RAYTRACER_UNTILS_H
#define RAYTRACER_UNTILS_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Definition.h"

using namespace std;

class Utils {
public:
    static inline void logInfo(string message) {
        cout << "[INFO] " << message << endl;
    }
    static inline void logError(string message) {
        cout << "[ERR] " << message << endl;
    }
    static inline float fInverse(float x) {
        if (fIsZero(x)) return FLOAT_INFINITTY;
        else return 1.0f/x;
    }
    static inline bool fIsZero(float x) {
        return fabs(x) < FLOAT_EPSILLON;
    }
    static inline bool fIsPos(float x) {
        return x > FLOAT_EPSILLON;
    }
    static inline bool fIsNeg(float x) {
        return x < -FLOAT_EPSILLON;
    }
    static inline float fAbs(float x) {
        return fabs(x);
    }
    static inline int SHFunc(float x) { //sign holder
        if (fIsNeg(x)) return -1;
        else return 1;
    }
    static inline int NSHFunc(float x) {
        return -SHFunc(x);
    }

    template <typename T>
    static vector<T> concat(vector<T> v1, vector<T> v2);

    template <typename T>
    static int quickSelect(T* dat, int l, int r, int k);

    template <typename T>
    static void swap(T* t1, T* t2);

private:

};

#endif //RAYTRACER_UNTILS_H
