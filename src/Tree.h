//
// Created by Rui Chen on 10/1/15.
//

#ifndef RAYTRACER_TREE_H
#define RAYTRACER_TREE_H

#include "Definition.h"
#include "Utils.h"
#include <vector>

using namespace std;

class Node {
public:
    Node(): left(nullptr), right(nullptr) {}
    Node(Node* left, Node* right): left(left), right(right) {}
    Node* left;
    Node* right;

    vector<PrimitivePtr> sum() {
        if (left == nullptr) return right->sum();
        else if (right == nullptr) return left->sum();
        else return Utils::concat(left->sum(), right->sum());
    }

private:
    BoundingVolumePtr bvPtr;
};

class Leaf {
public:
    Leaf(): Node() {}

    vector<PrimitivePtr> sum() {
        return vector<PrimitivePtr>{pPtr};
    }

private:
    PrimitivePtr pPtr;
};

class Tree {
public:
    Tree(): root(nullptr) {}
    bool isEmpty() { return root == nullptr; }

    virtual void buildWith(vector<PrimitivePtr> pPtrs) = 0;
    Node* root;
};

#endif //RAYTRACER_TREE_H
