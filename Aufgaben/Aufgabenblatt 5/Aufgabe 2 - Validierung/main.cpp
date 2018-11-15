#include <iostream>
#include "TreeUtil.h"

int main()
{
    std::vector<int> input = {20, 12, 34, 9, 19, 29};
    if (TreeUtil::isBinarySearchTree(input)) {
        std::cout << "Der Suchbaum ist valide.";
    } else {
        std::cout << "Der Suchbaum ist nicht valide.";
    }

    return 0;
}