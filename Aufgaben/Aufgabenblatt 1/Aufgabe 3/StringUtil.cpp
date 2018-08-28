#include "StringUtil.h"
#include <iostream>

bool StringUtil::checkUniqueness(string s)
{
    int seenChars[26] = {0};

    // Normalize input
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);

    for (char i : s) {
        if (seenChars[i - 65] == 0) { // Is index (A - 65 = 0) set?
            seenChars[i - 65] = 1;
        } else {
            return false;
        }
    }

    return true;
}
