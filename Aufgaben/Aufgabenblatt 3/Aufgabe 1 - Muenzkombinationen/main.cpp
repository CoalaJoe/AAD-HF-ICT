/**
 * In dieser Aufgabe soll ein Algorithmus implementiert werden, welcher für einen bestimmten Geldbetrag
 * die minimale Anzahl Münzen berechnet.
 *
 * Der Algorithmus erhält als Input den Betrag sowie ein Array mit den verfügbaren Münzen.
 */

#include <iostream>
#include "CoinCombination.h"

int main()
{
    double value1  = 10.50;
    auto   *coins1 = new double[3]{0.10, 0.05, 0.20};

    CoinCombination::printCoinCombination(value1, coins1, 3);

    return 0;
}
