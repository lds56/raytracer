//
// Created by Rui Chen on 9/18/15.
//

#ifndef RAYTRACER_UNTILS_H
#define RAYTRACER_UNTILS_H

#include <iostream>
#include <string>

using namespace std;

class Utils {
public:
    static inline void logInfo(string message) {
        cout << "[INFO] " << message << endl;
    }
    static inline void logError(string message) {
        cout << "[ERR] " << message << endl;
    }
};

#endif //RAYTRACER_UNTILS_H
