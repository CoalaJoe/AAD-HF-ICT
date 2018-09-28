/**
 * In dieser Aufgabe soll eine Methode implementiert werden, welche von 2 Zeichenketten den längsten Substring findet,
 * welcher in beiden Zeichenketten vorkommt
 *
 * https://www.sanfoundry.com/cpp-program-implement-suffix-tree/
 * https://www.geeksforgeeks.org/ukkonens-suffix-tree-construction-part-1/
 */

#include <iostream>
#include "SuffixTree.h"
#include "StringUtil.h"

int main()
{
    StringUtil::lcs("Das ist ein Test", "Das ist kein Test.");

    return 0;
}
