#include <iostream>
#include "Trader.h"

/**
 * Returns the maximum possible profit for that sequence.
 *
 * @param values
 * @param ARRAY_SIZE
 * @return
 */
int Trader::calculateMaxProfit(const int *values, const int ARRAY_SIZE)
{
    int *maxPrice = new int[ARRAY_SIZE];
    int *winnings = new int[ARRAY_SIZE];

    // Generate array with highest upcomming winnings.
    int lastMaxPrice = values[ARRAY_SIZE - 1];

    for (int i = ARRAY_SIZE - 1; i >= 0; --i) {
        if (values[i] > lastMaxPrice) {
            lastMaxPrice = values[i];
        }
        maxPrice[i] = lastMaxPrice;
    }

    // Calculate optimal entry point.
    int entryPoint    = 0;
    int currentProfit = maxPrice[1] - values[0];

    for (int i = 0; i < ARRAY_SIZE - 1; ++i) { // Don't do the last period.
        winnings[i] = maxPrice[i+1] - values[i];
        if (winnings[i] > currentProfit) {
            currentProfit = winnings[i];
            entryPoint    = i;
        }
    }

    std::cout << "Value:\t\t\t\t\t";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << values[i] << "\t";
    }
    std::cout << "\n";
    std::cout << "Highest upcoming price:\t";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << maxPrice[i] << "\t";
    }
    std::cout << "\n";
    std::cout << "Highest winning: \t\t";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << winnings[i] << "\t";
    }
    std::cout << "\n";
    std::cout << "\n";

    return winnings[entryPoint];
}
