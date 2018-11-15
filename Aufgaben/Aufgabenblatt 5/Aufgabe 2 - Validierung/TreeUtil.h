#ifndef AUFGABE_2_VALIDIERUNG_TREEUTIL_H
#define AUFGABE_2_VALIDIERUNG_TREEUTIL_H

#include <vector>

class TreeUtil {
public:
    static bool isBinarySearchTree(std::vector<int> values);

protected:
    static bool isBinarySearchTree(std::vector<int> values, int nodePos);
    static int getLeftNode(std::vector<int> values, int nodePos);
    static int getRightNode(std::vector<int> values, int nodePos);
};


#endif //AUFGABE_2_VALIDIERUNG_TREEUTIL_H
