#include "CoinCombination.h"
#include <iostream>
#include "stdio.h"

void CoinCombination::printCoinCombination(double value, const double *coins, const int ARRAY_SIZE)
{
    printf("Betrag: %0.2f CHF\n", value);
    std::sort(coins, coins + ARRAY_SIZE);
    std::string outputBuffer;

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        outputBuffer += std::to_string(coins[i]);
        if (i + 1 != ARRAY_SIZE) {
            outputBuffer += ", ";
        }
    }
    std::cout << "Münzen: " << outputBuffer << "\n";
    std::cout << "Resultat: ";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        outputBuffer += std::to_string(value / coins[i]);
        // TODO: No modulo...
        value = value % coins[i];
        if (i + 1 != ARRAY_SIZE) {
            outputBuffer += ", ";
        }
    }
}
