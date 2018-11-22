#include <utility>
#include <utility>
#include <iostream>
#include "TreeUtil.h"

void TreeUtil::printMaximumPath(std::vector<int> values) {
    std::vector<path> paths;
    path path;

    // Build all possible paths into paths
    getPath(paths, path, std::move(values), 0);

    // Index of path with highest value
    int maxPath = -1;
    // The highest value found.
    int maxValue = 0;

    for (int i = 0; i < paths.size(); ++i) {
        int sum = 0;
        auto nv = paths[i];
        for (auto const &n : nv) {
            sum += n;
        }
        if (maxPath == -1 || sum > maxValue) {
            maxPath = i;
            maxValue = sum;
        }
    }

    if (maxPath != -1) {
        for (auto const &n : paths[maxPath]) {
            std::cout << n << ", ";
        }
        std::cout << " (dieser Pfad ergibt die maximale Summe " << maxValue << ")";
    }
}

void TreeUtil::getPath(std::vector<path> &paths, path currentPath, std::vector<int> values, int nodePos) {
    int leftNodePos = getLeftNode(values, nodePos);
    int rightNodePos = getRightNode(values, nodePos);

    currentPath.push_back(values[nodePos]);

    if (leftNodePos != -1) {
        getPath(paths, currentPath, values, leftNodePos);
    }
    if (rightNodePos != -1) {
        getPath(paths, currentPath, values, rightNodePos);
    }
    if (leftNodePos == -1 && rightNodePos == -1) {
        paths.push_back(currentPath);
    }

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
