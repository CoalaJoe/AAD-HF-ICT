#include "SuffixNode.h"

const std::string &SuffixNode::getValue() const
{
    return value;
}

void SuffixNode::setValue(const std::string &value)
{
    SuffixNode::value = value;
}

SuffixNode::SuffixNode(int start, int *end, SuffixNode *root)
{
    this->suffixLink = root;
    this->start      = start;
    this->end        = end;

    // suffixIndex will be set to -1 by default and
    // actual suffix index will be set later for leaves
    this->suffixIndex = -1;
}

SuffixNode::SuffixNode()
{

}
