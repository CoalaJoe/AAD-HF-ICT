#ifndef AUFGABE_3_BIGGEST_SUBSTRING_SUFFIXNODE_H
#define AUFGABE_3_BIGGEST_SUBSTRING_SUFFIXNODE_H


#include <string>
#include <vector>

class SuffixNode {
private:
    std::string value;

    SuffixNode *suffixLink;

    int start;
    int *end;
    int suffixIndex;
public:
    SuffixNode(int start, int *end, SuffixNode *root);
    SuffixNode();

    std::vector<SuffixNode> nodes;

    const std::string &getValue() const;

    void setValue(const std::string &value);
};


#endif //AUFGABE_3_BIGGEST_SUBSTRING_SUFFIXNODE_H
