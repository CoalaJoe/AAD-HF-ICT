#include <iostream>
#include <vector>
#include <codecvt>
#include <map>
#include "StringUtil.h"


wchar_t StringUtil::getLonelyElement(std::wstring input)
{
    std::map<wchar_t, long>                                   set;
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;

    for (wchar_t &c : input) {
        set[c]++;
    }

    for (auto &c : set) {
        if (c.second == 1) {
            return c.first;
        }
    }

    return (wchar_t) '0';
}

#define SIZE 128

char StringUtil::getLonelyElement(string input)
{
    int set[SIZE] = {};

    for (char &c : input) {
        ++set[(int) c];
    }

    for (int i = 0; i < SIZE; ++i) {
        if (set[i] == 1) {
            return (char) i;
        }
    }

    return 0;
}
