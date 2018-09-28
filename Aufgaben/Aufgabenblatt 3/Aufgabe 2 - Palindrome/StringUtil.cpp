#include "StringUtil.h"
#include <iostream>

bool StringUtil::isPalindrome(string str)
{
    long int length = str.length();

    char first = tolower(str.substr(0, 1).at(0));
    char last  = tolower(str.substr(length - 1, 1).at(0));

    if (first == last) {
        if (str.length() <= 1) return true;
    } else {
        return false;
    }
}
