/**
 * Implementieren Sie eine Methode getLonelyElement welche als Parameter einen string bekommt.
 * Jeder Character in diesem string kommt zweimal vor, ausser eines.
 * Die Methode soll das Element zurückliefern, welches nur einmal vorkommt.
 *
 * Beispiel:
 * Input: abcdedcba11
 * Resultat: e (das Element e kommt nur einmal vor)
 */

#include <iostream>
#include "StringUtil.h"
#include <codecvt>

int main()
{
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;

    clock_t start, stop;
    start = clock();
    //char32_t result = StringUtil::getLonelyElement(U"abcäddcba11");
    char result = StringUtil::getLonelyElement("abcdedcba11");
    stop = clock();
    std::cout << "Time: " << std::fixed << (double) (stop-start) / CLOCKS_PER_SEC << "sec" << std::endl;
    //std::cout << "Character '" << converter.to_bytes(result) << "' found.\n";
    std::cout << "Character '" << result << "' found.\n";
    if (U'e' == result) {
        std::cout << "Success";
        return 0;
    }
    std::cout << "Error";

    return 1;
}