#include <utility>
#include <climits>
#include <iostream>
#include "TreeUtil.h"

bool TreeUtil::isBinarySearchTree(std::vector<int> values) {
    return isBinarySearchTree(std::move(values), 0, INT_MIN, INT_MAX);
}

bool TreeUtil::isBinarySearchTree(std::vector<int> values, int nodePos, int leftBound, int rightBound) {
    int nodeLeft = getLeftNode(values, nodePos);
    int nodeRight = getRightNode(values, nodePos);
    bool valid = true;

    if (nodeLeft != -1) {
        if (values[nodeLeft] < values[nodePos] && values[nodeLeft] > leftBound) {
            valid &= isBinarySearchTree(values, nodeLeft, leftBound, values[nodePos]);
        } else {
            return false;
        }
    }
    if (nodeRight != -1) {
        if (values[nodeRight] > values[nodePos] && values[nodeRight] < rightBound) {
            valid &= isBinarySearchTree(values, nodeRight, values[nodePos], rightBound);
        } else {
            return false;
        }
    }

    return valid;
}

int TreeUtil::getRightNode(std::vector<int> values, int nodePos) {
    int rightNode = nodePos * 2 + 2;
    if (values.size() <= rightNode) {
        return -1;
    }

    return rightNode;
}

int TreeUtil::getLeftNode(std::vector<int> values, int nodePos) {
    int leftNode = nodePos * 2 + 1;
    if (values.size() <= leftNode) {
        return -1;
    }

    return leftNode;
}
