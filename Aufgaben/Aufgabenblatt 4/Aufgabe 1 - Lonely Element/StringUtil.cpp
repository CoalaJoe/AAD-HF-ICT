#include <iostream>
#include <vector>
#include "StringUtil.h"


char StringUtil::getLonelyElement(string input)
{
    int set[128] = {};

    for (char &c : input) {
        ++set[(int) c];
    }

    for (int i = 0; i < 128; ++i) {
        if (set[i] == 1) {
            return (char) i;
        }
    }

    return 0;
}

