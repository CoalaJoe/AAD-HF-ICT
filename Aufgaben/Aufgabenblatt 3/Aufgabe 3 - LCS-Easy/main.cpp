#include <iostream>
#include "StringUtil.h"

int main()
{
    std::cout << StringUtil::lcs("Das ist ein Test.", "Das ist kein Test.") << "\n";
    std::cout << StringUtil::lcs("Das ist ein Test", "Das ist kein Test.") << "\n";
    return 0;
}