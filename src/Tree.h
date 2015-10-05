//
// Created by Rui Chen on 10/1/15.
//

#ifndef RAYTRACER_TREE_H
#define RAYTRACER_TREE_H

#include "Definition.h"
#include "Utils.h"
#include "BoundingVolume.h"
#include "Primitive.h"
#include <vector>

using namespace std;

class Node {
public:
    Node(): left(nullptr), right(nullptr), bvPtr(nullptr) {}
    Node(Node* left, Node* right): left(left), right(right) {}
    Node(vector<PrimitivePtr> pPtrs, int axisFlag); // see in cpp

    Node* left;
    Node* right;

    virtual vector<PrimitivePtr> sum() {
        if (left == nullptr) return right->sum();
        else if (right == nullptr) return left->sum();
        else return Utils::concat(left->sum(), right->sum());
    }

    virtual ~Node() {delete left; delete right;}

    static Node* buildTree(vector<PrimitivePtr> pPtrs, int axisFlag);

protected:
    BoundingVolumePtr bvPtr;
};

class Leaf : public Node {
public:
    Leaf(): Node() {}
    Leaf(PrimitivePtr pPtr): Node(), pPtr(pPtr) {}

    vector<PrimitivePtr> sum() {
        return vector<PrimitivePtr>{pPtr};
    }

protected:
    PrimitivePtr pPtr;
};

#endif //RAYTRACER_TREE_H
