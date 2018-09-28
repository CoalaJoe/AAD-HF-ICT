#include <utility>

#include "SuffixTree.h"
#include <iostream>


void SuffixTree::build(std::string s1)
{
    SuffixNode    *similarNode     = nullptr;
    unsigned long similarityLength = 0;
    unsigned long i;
    int           lengthOfSmallerNode;

    for (auto &node : this->nodes) {
        if (node.getValue().at(0) == s1.at(0)) {
            lengthOfSmallerNode = static_cast<int>((node.getValue().length() > s1.length()) ? s1.length()
                                                                                            : node.getValue().length());

            for (i = 0; i < lengthOfSmallerNode; ++i) {
                if (node.getValue().at(i) != s1.at(i)) {
                    // Not similar anymore
                    if (similarityLength < i) {
                        similarityLength = i;
                        similarNode      = &node;
                        break;
                    }
                }
            }
        }
    }
    if (similarityLength != 0) {
        std::cout << "Similar Node found: " << "\"" << similarNode->getValue() << "\" with string \"" << s1
                  << "\" at length " << similarityLength << "\n";
        // If similarityLength is length of Node, append Node to Node.
        if (similarityLength + 1 == similarNode->getValue().length()) {
            SuffixNode newNode;
            newNode.setValue(s1.erase(0, similarityLength)); // Remove similarNode value from new node.
            similarNode->nodes.push_back(newNode);
        } else {
            // Strip similarNode and new node. Update children
            //similarNode->setValue(similarNode->getValue().substr(0, similarityLength));
            for (auto &nestedNodes: similarNode->nodes) {
                nestedNodes.setValue(nestedNodes.getValue().substr(0, similarityLength));
            }

            SuffixNode newNode;
            newNode.setValue(s1.erase(0, similarityLength)); // Remove similarNode value from new node.
            similarNode->nodes.push_back(newNode);
        }
    } else { // If none is found. Append to root.
        SuffixNode node;
        node.setValue(s1);
        this->nodes.push_back(node);
    }

    // Remove first letter.
    s1.erase(0, 1);
    if (!s1.empty()) {
        build(s1);
    }
}

std::string SuffixTree::getLongestCommonString(std::string input1, std::string input2)
{
    // Add character to distinguish end of string in nodes.
    this->build(std::move(input1 + "$"));

    for (const auto &node: this->nodes) {
        std::cout << "\"" << node.getValue() << "\"\n";
        if (!node.nodes.empty()) {
            for (const auto &innerNode: this->nodes) {
                std::cout << "---> \"" << innerNode.getValue() << "\"\n";
            }
        }
    }

    return std::string();
}
