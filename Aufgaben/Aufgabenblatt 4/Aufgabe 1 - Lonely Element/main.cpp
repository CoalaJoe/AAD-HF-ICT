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

int main()
{
    clock_t start, stop;
    start = clock();
    char result = StringUtil::getLonelyElement(u8"abcdedcba11");
    stop = clock();
    std::cout << "Time: " << std::fixed << (double) (stop-start) / CLOCKS_PER_SEC << "sec" << std::endl;
    if ('e' == result) {
        std::cout << "Success";
        return 0;
    }
    std::cout << "Error";

    return 1;
}