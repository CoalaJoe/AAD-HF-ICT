#ifndef AUFGABE_3_BIGGEST_SUBSTRING_SUFFIXNODE_H
#define AUFGABE_3_BIGGEST_SUBSTRING_SUFFIXNODE_H


#include <string>
#include <vector>

class SuffixNode {
private:
    std::string value;
public:
    std::vector<SuffixNode> nodes;

    const std::string &getValue() const;

    void setValue(const std::string &value);

    bool isLeafNode();
};


#endif //AUFGABE_3_BIGGEST_SUBSTRING_SUFFIXNODE_H
