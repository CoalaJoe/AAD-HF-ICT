/**
 * Gegeben ist ein binärer Baum in Form eines Array. Das Element an Position 0 ist der Root Knoten
 *
 * Implementieren  Sie  eine  Methode,  welche  einen  Baum  in  Array  Form  bekommt.
 * Diese Methode liefert true, falls es sich um einen binären Suchbaum handelt.
 * Falls es lediglich ein binärer Baum ist, liefert die Methode false.
 */

#include <iostream>
#include "TreeUtil.h"

int main()
{
    //std::vector<int> input = {20, 12, 34, 9, 19, 29};
    std::vector<int> input = {20, 112, 34, 9, 19, 29};
    if (TreeUtil::isBinarySearchTree(input)) {
        std::cout << "Der Suchbaum ist valide.";
    } else {
        std::cout << "Der Suchbaum ist nicht valide.";
    }

    return 0;
}
