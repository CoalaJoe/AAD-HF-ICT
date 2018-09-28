#include <utility>

#include "StringUtil.h"
#include "SuffixTree.h"

string StringUtil::lcs(string input1, string input2)
{
    auto tree = new SuffixTree();
    // std::move to minimize unnecessary copies.
    return tree->getLongestCommonString(std::move(input1), std::move(input2));
}
