#include "SuffixTree.h"
#include <iostream>

SuffixNode *SuffixTree::build(std::string s)
{
    int stringSize = static_cast<int>(s.length());
    int *a         = new int[stringSize];

    // Map string to alphabet.
    for (int i = 0; i < stringSize; ++i) {
        a[i] = static_cast<int>(alphabet.find(s.at(static_cast<unsigned long>(i))));
    }

    auto       *root = new SuffixNode(0, 0, 0, nullptr);
    SuffixNode *cn   = root;
    root->suffixLink = root;
    SuffixNode *needsSuffixLink = nullptr;

    int lastRule = 0;
    int i, j     = 0;

    for (i = -1; i < stringSize - 1; i++) {
        int cur = a[i + 1];
        for (; j <= i + 1; j++) {
            int curDepth = i + 1 - j;
            if (lastRule != 3) {
                if (cn->suffixLink != nullptr)
                    cn = cn->suffixLink;
                else
                    cn = cn->parent->suffixLink;
                int k  = j + cn->depth;
                while (curDepth > 0 && !cn->contains(curDepth - 1)) {
                    k += cn->end - cn->begin;
                    cn = cn->children[a[k]];
                }
            }
            if (!cn->contains(curDepth)) {
                if (needsSuffixLink != nullptr) {
                    needsSuffixLink->suffixLink = cn;
                    needsSuffixLink = nullptr;
                }
                if (cn->children[cur] == nullptr) {
                    cn->children[cur] = new SuffixNode(i + 1, stringSize, curDepth, cn);
                    lastRule = 2;
                } else {
                    cn       = cn->children[cur];
                    lastRule = 3;
                    break;
                }
            } else {
                int end = cn->begin + curDepth - cn->depth;
                if (a[end] != cur) {
                    auto *newn = new SuffixNode(cn->begin, end, cn->depth, cn->parent);
                    newn->children[cur]                = new SuffixNode(i + 1, stringSize, curDepth, newn);
                    newn->children[a[end]]             = cn;
                    cn->parent->children[a[cn->begin]] = newn;
                    if (needsSuffixLink != nullptr)
                        needsSuffixLink->suffixLink = newn;
                    cn->begin                       = end;
                    cn->depth                       = curDepth;
                    cn->parent                      = newn;
                    cn       = needsSuffixLink = newn;
                    lastRule = 2;
                } else if (cn->end != stringSize || (cn->begin - cn->depth) < j) {
                    lastRule = 3;
                    break;
                } else
                    lastRule = 1;
            }
        }
    }
    root->suffixLink = nullptr;
    return root;
}

int SuffixTree::findLCS(SuffixNode *node, int i1, unsigned long i2)
{
    if (node->begin <= i1 && i1 < node->end)
        return 1;
    if (node->begin <= i2 && i2 < node->end)
        return 2;
    int      mask = 0;
    for (int f    = 0; f < alphabetSize; f++) {
        if (node->children[f] != nullptr) {
            mask |= findLCS(node->children[f], i1, i2);
        }
    }
    if (mask == 3) {
        int curLength = node->depth + node->end - node->begin;
        if (lcsLength < curLength) {
            lcsLength     = curLength;
            lcsBeginIndex = node->begin;
        }
    }
    return mask;
}

void SuffixTree::findLCS(std::string s1, std::string s2)
{
    std::string x     = "-";
    std::string y     = "#";
    // Building appropriate string with delimiters.
    std::string s     = s1.append(x.append(s2.append(y)));
    SuffixNode  *root = build(s);
    lcsLength     = 0;
    lcsBeginIndex = 0;
    findLCS(root, static_cast<int>(s1.length()), static_cast<int>(s1.length() + s2.length() + 1));
    bool chk = lcsLength > 0;
    if (chk) {
        std::cout << "\nLongest substring is " << s.substr(static_cast<unsigned long>(lcsBeginIndex),
                                                           static_cast<unsigned long>(lcsLength)) << "\n";
    } else {
        std::cout << "No substring found\n";
    }
}
