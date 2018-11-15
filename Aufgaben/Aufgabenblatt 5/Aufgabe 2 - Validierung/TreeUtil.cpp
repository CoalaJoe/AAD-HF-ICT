#include <utility>

#include <iostream>
#include "TreeUtil.h"

bool TreeUtil::isBinarySearchTree(std::vector<int> values)
{
    return isBinarySearchTree(std::move(values), 0);
}

bool TreeUtil::isBinarySearchTree(std::vector<int> values, int nodePos)
{
    std::cout << "Runnung Recursion on array id " << nodePos << "\n";
    int nodeLeft = getLeftNode(values, nodePos);
    int nodeRight = getRightNode(values, nodePos);
    bool valid = true;

    if (nodeLeft != -1 && values[nodeLeft] > values[nodePos]) {
        std::cout << "Left recursion for " << values[nodePos] << "\n";
        valid = isBinarySearchTree(values, nodeLeft);
    }
    if (nodeRight != -1 && values[nodeRight] > values[nodePos]) {
        std::cout << "Right recursion for " << values[nodePos] << "\n";
        valid = isBinarySearchTree(values, nodeRight);
    }

    return valid;
}

int TreeUtil::getRightNode(std::vector<int> values, int nodePos)
{
    int rightNode = nodePos * 2 + 2;
    if (values.size() <= rightNode) {
        return -1;
    }

    return rightNode;
}

int TreeUtil::getLeftNode(std::vector<int> values, int nodePos)
{
    int leftNode = nodePos * 2 + 1;
    if (values.size() <= leftNode) {
        return -1;
    }

    return leftNode;
}
