/**
 * Aufgabe 2: Array Multiplikation
 *
 * In dieser Aufgabe soll eine Methode implementiert werden, welche als Parameter einen Array enthält.
 * Das Resultat ist ein Array der gleichen Grösse.
 * Jedes Element dieses Arrays beinhaltet die Multiplikation aller Elemente (ausser sich selbst) des Input Arrays.
 *
 * ACHTUNG: Der Divisionsoperator darf in dieser Aufgabe NICHT verwendet werden!
 *
 * Eingabe: {12, 4, 7, 3}
 * Erwartete Ausgabe: {84, 252, 144, 336}
 */

#include <iostream>
#include "ArrayUtil.h"

int main()
{
    int  SIZE    = 4;
    long input[] = {12, 4, 7, 3};
    long *output = ArrayUtil::multiplyArrayValues(input, SIZE);

    for (int i = 0; i < SIZE; ++i) {
        std::cout << i << ": " << output[i] << "\n";
    }

    return 0;
}