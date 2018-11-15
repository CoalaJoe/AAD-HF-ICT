/**
 * Gegeben ist ein binärer Baum (nicht ein binärer Suchbaum) in Array Form.
 * Finden Sie den Pfad zum Blatt, bei welchem alle die Werte aller Nodes zusammengezählt, maximiert wird.
 *
 * Der Baum: 40, 100, 200, 20, 40, 70, 80, 50, 10
 */

#include <iostream>
#include "TreeUtil.h"

int main() {
    std::vector<int> input = {40, 100, 200, 20, 40, 70, 80, 50, 10};

    TreeUtil::printMaximumPath(input);
    return 0;
}
