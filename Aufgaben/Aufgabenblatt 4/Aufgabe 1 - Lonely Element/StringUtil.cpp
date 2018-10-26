#include <iostream>
#include <vector>
#include <codecvt>
#include "StringUtil.h"


char32_t StringUtil::getLonelyElement(std::u32string input)
{
    int set[256] = {};
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;

    for (char32_t &c : input) {
        ++set[(int) c];
    }

    for (int i = 0; i < 256; ++i) {
        if (set[i] == 1) {
            return (char32_t) i;
        }
    }

    return 0;
}

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
