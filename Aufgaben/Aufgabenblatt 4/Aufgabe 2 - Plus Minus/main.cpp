/**
 * Implementieren Sie eine Methode analyseArray welche als Parameter einen vector mit Integer Werten bekommt. 
 * Diese Werte sind entweder Positiv, Negativ oder Null. 
 * Die Methode soll nun berechnen, wie viel Prozent der Werte Positiv, Negativ resp. Null sind. 
 * Diese drei Werte werden als Objekt der Klasse Result zuruckgeliefert.
 */

#include <iostream>
#include "ArrayUtil.h"

int main()
{
    std::vector<int> input = {1, 10, 0, -6, -9, 2, 5};
    ArrayUtil::analyzeArray(input);

    return 0;
}
