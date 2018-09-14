/**
 * In dieser Aufgabe soll eine Methode implementiert werden, welche als Parameter zwei Strings enthält.
 * Die Methode liefert den Wert true, falls diese beiden Strings Anagramme sind. Anonsten false.
 */

#include <iostream>
#include "StringUtil.h"

int main()
{
    if (StringUtil::anagramCheck("Hallo", "ollaH")){
        std::cout << "CORRECT!\n";
    } else {
        std::cout << "WRONG!\n";
    }

    if (StringUtil::anagramCheck("Hasllo", "ollaH")){
        std::cout << "WRONG!\n";
    } else {
        std::cout << "CORRECT!\n";
    }

    return 0;
}