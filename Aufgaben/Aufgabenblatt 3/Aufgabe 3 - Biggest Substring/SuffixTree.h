#ifndef AUFGABE_3_BIGGEST_SUBSTRING_SUFFIXTREE_H
#define AUFGABE_3_BIGGEST_SUBSTRING_SUFFIXTREE_H

#include <string>
#include <vector>
#include "SuffixNode.h"

class SuffixTree {
private:
    std::vector<SuffixNode> nodes;
    void build(std::string s1);

public:
    std::string getLongestCommonString(std::string input1, std::string input2);
};

#endif //AUFGABE_3_BIGGEST_SUBSTRING_SUFFIXTREE_H
