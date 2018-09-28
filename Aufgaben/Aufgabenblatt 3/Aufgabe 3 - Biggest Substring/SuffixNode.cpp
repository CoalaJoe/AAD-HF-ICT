#include "SuffixNode.h"

SuffixNode::SuffixNode(int begin, int end, int depth, SuffixNode *parent)
{
    children = new SuffixNode* [38];
    this->begin = begin;
    this->end = end;
    this->parent = parent;
    this->depth = depth;
}

bool SuffixNode::contains(int d)
{
    return depth <= d && d < depth + (end - begin);
}
