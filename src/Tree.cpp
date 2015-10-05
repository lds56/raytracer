//
// Created by Rui Chen on 10/1/15.
//

#include "Tree.h"


Node :: Node(vector<PrimitivePtr> pPtrs, int axisFlag) {

    auto fightPower = [](PrimitivePtr p) { return (p->getBV()->getMinCorner())(axisFlag); };
    auto l = Utils::map(pPtrs, fightPower);

    float midExt = Utils::findMedian(l);
    Point3d maxExt = pPtrs[0]->getBV()->getMaxCorner();
    Point3d minExt = pPtrs[0]->getBV()->getMinCorner();

    vector<PrimitivePtr> leftPtrs, rightPtrs;
    for (auto pPtr : pPtrs) {
        // find minExt and maxExt
        maxExt = Point3d::pointMax(maxExt, pPtr->getBV()->getMaxCorner());
        minExt = Point3d::pointMax(minExt, pPtr->getBV()->getMinCorner());
        // split
        if (fightPower(pPtr) < midExt) leftPtrs.push_back(pPtr);
        else rightPtrs.push_back(pPtr);
    }

    bvPtr = BoundingVolumePtr( new BoundingVolume(minExt, maxExt) );

    left = buildTree(leftPtrs, (axisFlag + 1) % 3);
    right = buildTree(rightPtrs, (axisFlag + 1) % 3);

};


Node* Node :: buildTree(vector<PrimitivePtr> pPtrs, int axisFlag) {
    if (pPtrs.size() > 1) {
        return new Node(pPtrs, (axisFlag + 1) % 3);
    } else if (pPtrs.size() == 1) {
        return new Leaf(pPtrs[0]);
    } else {
        return nullptr;
    }
}