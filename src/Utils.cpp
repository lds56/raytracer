//
// Created by Rui Chen on 9/18/15.
//
#include "Utils.h"

template <typename T>
vector<T> Utils::concat(vector<T> v1, vector<T> v2)
{
    if (v1.size() > v2.size()) {
        v1.insert(v1.end(), v2.begin(), v2.end());
        return v1;
    } else {
        v2.insert(v2.end(), v1.begin(), v1.end());
        return v2;
    }
}

/*
 *  Refrence: https://en.wikipedia.org/wiki/Quickselect
 * */

template <typename T>
int Utils::quickSelect(T* dat, int left, int right, int k) {
    int pivot = left + rand() * (right - left + 1);
    int pivotValue = dat[pivot];
    swap(dat + pivot, dat + right);
    int stored = left;
    for (int i=left; i<=right; i++) {
        if (dat[i] < pivotValue) {
            swap(dat + stored, dat + i);
            stored++;
        }
    }
    swap(right, stored);
    if (k == stored) return dat[k];
    else if (k < stored) return quickSelect(dat, left, stored - 1, k);
    else return quickSelect(dat, stored + 1, right, k);
}

template <typename T>
void Utils::swap(T* t1, T* t2) {
    T* tmp = t1;
    t1 = t2;
    t2 = tmp;
    free(tmp);
}