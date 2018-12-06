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
    // Valid
    std::vector<int> input1 = {20, 12, 34, 9, 19, 29};
    // Invalid
    std::vector<int> input2 = {20, 112, 34, 9, 19, 29};
    // Invalid
    std::vector<int> input3 = {20, 12, 34, 9, 24, 29};
    // Invalid
    std::vector<int> input4 = {10, 8, 12, 9};


    std::cout << "Valider Baum ist: ";
    if (TreeUtil::isBinarySearchTree(input1)) {
        std::cout << "valide\n";
    } else {
        std::cout << "nicht valide\n";
    }

    std::cout << "Invalider Baum ist: ";
    if (TreeUtil::isBinarySearchTree(input2)) {
        std::cout << "valide\n";
    } else {
        std::cout << "nicht valide\n";
    }

    std::cout << "Invalider Baum ist: ";
    if (TreeUtil::isBinarySearchTree(input3)) {
        std::cout << "valide\n";
    } else {
        std::cout << "nicht valide\n";
    }

    std::cout << "Invalider Baum ist: ";
    if (TreeUtil::isBinarySearchTree(input4)) {
        std::cout << "valide\n";
    } else {
        std::cout << "nicht valide\n";
    }

    return 0;
}
