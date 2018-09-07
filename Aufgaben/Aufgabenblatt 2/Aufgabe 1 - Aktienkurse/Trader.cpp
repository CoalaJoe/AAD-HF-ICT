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
    int  previousValue = values[0];
    int  startIndex;
    int  startValue;
    int  investment;
    bool foundStart    = false;

    // Get first spike and buy before.
    for (int i = 1; i < ARRAY_SIZE; ++i) {
        if (previousValue < values[i]) {
            startIndex = i;
            startValue = values[i];
            investment = startValue;
            foundStart = true;
            break;
        }
        previousValue = values[i];
    }
    if (!foundStart) {
        std::cout << "Do not waste your money on this one.";
        return 0;
    }

    for (int i = startIndex; i < ARRAY_SIZE; ++i) {
        if (i + 2 < ARRAY_SIZE) { // I have at least 2 more cycles.
            if (values[i] < values[i + 1]) { // The one cycle after the next is more lucrative.
                continue;
            } else if (investment < values[i]) { // Next Cycle is better than this.
                investment = values[i];
            } else { // Bad times ahead.
                continue;
            }

        } else if (i + 1 < ARRAY_SIZE) { // I have one more cycle.

        } else { // Last cycle.

        }

    }

    return investment - startValue;
}
