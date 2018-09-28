/**
 * In dieser Aufgabe soll eine Methode implementiert werden, welche mit Hilfe von Rekursion prüft, ob eine Zeichenkette
 * ein Palindrome ist.
 */
#include <iostream>
#include "StringUtil.h"

int main()
{
    if (StringUtil::isPalindrome("Otto")) {
        std::cout << "Okay";
    } else {
        std::cout << "Wrong!";
    }
    if (StringUtil::isPalindrome("Peter")) {
        std::cout << "Wrong!";
    } else {
        std::cout << "Okay";
    }

    return 0;
}