//
// Created by Rui Chen on 9/18/15.
//

#ifndef RAYTRACER_UNTILS_H
#define RAYTRACER_UNTILS_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

const float BV_EPSILLON = 1.0E-5f;
const float FLOAT_EPSILLON = 1.0E-5f;
const float FLOAT_INFINITTY = 1.0E+10f;

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
    static vector<T> concat(vector<T> v2, vector<T> v1) {
        if (v1.size() > v2.size()) {
            v1.insert(v1.end(), v2.begin(), v2.end());
            return v1;
        } else {
            v2.insert(v2.end(), v1.begin(), v1.end());
            return v2;
        }
    }

    template <typename T>
    static float quickSelect(vector<T> dat, int left, int right, int k) {
        // index is k, (k+1)th

        int pivot = randInt(left, right);
        int pivotValue = dat[pivot];
        swap(dat[pivot], dat[right]);
        int stored = left;

        for (int i=left; i<=right; i++) {
            if (dat[i] < pivotValue) {
                swap(dat[stored], dat[i]);
                stored++;
            }
        }
        swap(dat[right], dat[stored]);

        if (k == stored) return dat[k];
        else if (k < stored) return quickSelect(dat, left, stored - 1, k);
        else return quickSelect(dat, stored + 1, right, k);
    }

    template <typename T>
    static float findMedian(vector<T> dat) {
        return quickSelect(dat, 0, dat.size()-1, dat.size()/2);
    }

    template <typename T>
    static void swap(T& t1, T& t2) {
        T tmp = t1;
        t1 = t2;
        t2 = tmp;
    }

    inline int static randInt(int max) {
        return randInt(0, max);
    }

    inline int static randInt(int min, int max) {
        srand(time(NULL));
        if (min == max) return min;
        else return min + rand() % (max - min);
    }

    /* functional function here */

    template <typename Collection,typename unop>
    static void for_each(Collection col, unop op){
        std::for_each(col.begin(),col.end(),op);
    }

    template <typename Collection,typename unop>
    static Collection map(Collection col,unop op) {
        std::transform(col.begin(),col.end(),col.begin(),op);
        return col;
    }

private:


};

#endif //RAYTRACER_UNTILS_H
