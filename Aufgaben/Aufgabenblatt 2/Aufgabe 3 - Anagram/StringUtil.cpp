#include <vector>
#include <iostream>
#include "StringUtil.h"

/**
 * Checks whether or not the given two strings are anagrams.
 *
 * @param s1
 * @param s2
 * @return
 */
bool StringUtil::anagramCheck(string s1, string s2)
{
    int sum1[26] = {0}, sum2[26] = {0};

    // Normalize input
    std::transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    std::transform(s2.begin(), s2.end(), s2.begin(), ::toupper);

    for (char c : s1) {
        sum1[c-65] += 1;
    }
    for (char c : s2) {
        sum2[c-65] += 1;
    }

    for (int i = 0; i < 25; ++i) {
        if (sum1[i] != sum2[i]) {
            return false;
        }
    }

    return true;
}
