#ifndef AUFGABE_3_BIGGEST_SUBSTRING_SUFFIXTREE_H
#define AUFGABE_3_BIGGEST_SUBSTRING_SUFFIXTREE_H

#include <string>
#include "SuffixNode.h"

class SuffixTree {
public:
    /**
     * Find longest common substring
     */
    void findLCS(std::string s1, std::string s2);

private:
    std::string   alphabet     = "abcdefghijklmnopqrstuvwxyz1234567890-#";
    unsigned long alphabetSize = alphabet.size();
    int           lcsLength;
    int           lcsBeginIndex;

    /**
     * Build suffix tree for given text
     */
    SuffixNode *build(std::string s);

    /**
     * Find longest common substring
     */
    int findLCS(SuffixNode *node, int i1, unsigned long i2);
};

#endif //AUFGABE_3_BIGGEST_SUBSTRING_SUFFIXTREE_H
