#ifndef AUFGABE_3_MAXIMUM_VALUE_TREEUTIL_H
#define AUFGABE_3_MAXIMUM_VALUE_TREEUTIL_H

#include <vector>

typedef std::vector<int> path;

class TreeUtil {
public:
    static void printMaximumPath(std::vector<int> values);
protected:
    static void getPath(std::vector<path> &paths, path currentPath, path values, int nodePos);
    static int getLeftNode(std::vector<int> values, int nodePos);
    static int getRightNode(std::vector<int> values, int nodePos);
};


#endif //AUFGABE_3_MAXIMUM_VALUE_TREEUTIL_H
