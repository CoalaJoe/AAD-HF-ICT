#include "SuffixNode.h"

const std::string &SuffixNode::getValue() const
{
    return value;
}

void SuffixNode::setValue(const std::string &value)
{
    SuffixNode::value = value;
}
