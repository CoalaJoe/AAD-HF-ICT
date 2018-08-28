/**
 * Aufgabe 3: String Check
 *
 * In dieser Aufgabe soll eine Methode implementiert werden, welche als Parameter einen String enthält.
 * Das Resultat ist ein Boolean.
 * true falls alle Buchstaben unique sind (alle Buchstaben kommen nur einmal vor), sonst false.
 */

#include <iostream>
#include "StringUtil.h"

int main()
{
    if (!StringUtil::checkUniqueness("abcdef")) {
        std::cout << "Failed!";
        return 1;
    }

    if (StringUtil::checkUniqueness("abcdCef")) {
        std::cout << "Failed!";
        return 1;
    }

    return 0;
}