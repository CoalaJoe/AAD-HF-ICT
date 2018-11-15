#include <utility>

#include <iostream>
#include "TreeUtil.h"

bool TreeUtil::isBinarySearchTree(std::vector<int> values) {
    return isBinarySearchTree(std::move(values), 0);
}

bool TreeUtil::isBinarySearchTree(std::vector<int> values, int nodePos) {
    int nodeLeft = getLeftNode(values, nodePos);
    int nodeRight = getRightNode(values, nodePos);
    bool valid = true;

    if (nodeLeft != -1) {
        if (values[nodeLeft] < values[nodePos]) {
            valid &= isBinarySearchTree(values, nodeLeft);
        } else {
            valid = false;
        }
    }
    if (nodeRight != -1) {
        if (values[nodeRight] > values[nodePos]) {
            valid &= isBinarySearchTree(values, nodeRight);
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
