#include "CoinCombination.h"
#include <iostream>
#include <cmath>
#include <iomanip>

void CoinCombination::printCoinCombination(double value, const double *coins, const int ARRAY_SIZE)
{
    //auto sortedCoins = new double[ARRAY_SIZE];
    //std::copy(coins, coins + ARRAY_SIZE, sortedCoins);
    //std::sort(sortedCoins, sortedCoins + ARRAY_SIZE);

    int amountOfCoins;

    printf("Betrag: %0.2f CHF\n", value);

    std::cout << "Münzen: ";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << coins[i];
        if (i + 1 != ARRAY_SIZE) {
            std::cout << ", ";
        }
    }
    std::cout << "\nResultat: ";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (value != 0) {
            amountOfCoins = (int)(round(value * 100) / round(coins[i] * 100));
            value -= (amountOfCoins * coins[i]);
        } else {
            amountOfCoins = 0;
        }
            std::cout << amountOfCoins;
        if (i + 1 != ARRAY_SIZE) {
            std::cout << ", ";
        }
    }
}
