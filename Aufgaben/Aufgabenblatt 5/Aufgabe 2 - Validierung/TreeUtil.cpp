#include <utility>
#include <limits>
#include <iostream>
#include "TreeUtil.h"

bool TreeUtil::isBinarySearchTree(std::vector<int> values) {
    int min = std::numeric_limits<int>::min();
    int max = std::numeric_limits<int>::max();

    return isBinarySearchTree(std::move(values), 0, min, max);
}

bool TreeUtil::isBinarySearchTree(std::vector<int> values, int nodePos, int leftBound, int rightBound) {
    int nodeLeft = getLeftNode(values, nodePos);
    int nodeRight = getRightNode(values, nodePos);
    bool valid = true;

    if (nodeLeft != -1) {
        if (values[nodeLeft] < values[nodePos] && values[nodeLeft] > leftBound) {
            valid &= isBinarySearchTree(values, nodeLeft, leftBound, values[nodePos]);
        } else {
            valid = false;
        }
    }
    if (nodeRight != -1) {
        if (values[nodeRight] > values[nodePos] && values[nodeRight] < rightBound) {
            valid &= isBinarySearchTree(values, nodeRight, values[nodePos], rightBound);
        } else {
            valid = false;
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
