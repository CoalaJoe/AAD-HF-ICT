/**
 * In dieser Aufgabe soll eine Methode implementiert werden, welche als Parameter einen Array enthält.
 * Dieser Array beinhaltet die Aktienpreise eines bestimmten Unternehmen für einen Tag.
 * Der Arrayindex ist dabei die Minute seit Start (Börse öffnet um 09:00 und schliesst um 17:30).
 *
 * stockprices[0]   = 100 // Wert der Aktie um 09:00
 * stockprices[1]   = 101 // Wert der Aktie um 09:01
 * stockprices[10]  = 89  // Wert der Aktie um 09:10
 * stockprices[70]  = 75  // Wert der Aktie um 10:10
 * stockprices[440] = 110 // Wert der Aktie um 16:20
 *
 * Finden Sie den maximalem Gewinn der an diesem Tag erzielt werden konnte.
 * ACHTUNG: "shorting" (Verkauf bevor Kauf) ist nicht erlaubt.
 * Ebenso ist es nicht erlaubt die Aktien zum gleichen Zeitpunkt zu kaufen und zuverkaufen.
 * Es kann durchaus möglich sein, dass der Gewinn negativ ist.
 */

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Trader.h"

int *buildTestSet(int size, int min, int max)
{
    srand (static_cast<unsigned int>(time(nullptr))); // Add true random numbers.
    int      *set = new int[size];
    for (int i    = 0; i < size; ++i) {
        set[i] = min + (rand() % (max - min));
    }

    return set;
}

int main()
{
    int testSet1[10] = {67, 109, 133, 118, 110, 132, 84, 138, 63, 89};
    int *testSet2 = buildTestSet(20, 40, 160);
    int testSet3[10] = {120, 109, 100, 90, 85, 70, 50, 30, 20, 10};
    int result1, result2, result3;

    std::cout << "Testset 1\n";
    result1 = Trader::calculateMaxProfit(testSet1, 10);
    std::cout << "\n";

    std::cout << "Testset 2\n";
    result2 = Trader::calculateMaxProfit(testSet2, 20);
    std::cout << "\n";

    std::cout << "Testset 3\n";
    result3 = Trader::calculateMaxProfit(testSet3, 10);
    std::cout << "\n";

    std::cout << "Maximaler Gewinn 1: " << result1 << "\n";
    std::cout << "Maximaler Gewinn 2: " << result2 << "\n";
    std::cout << "Maximaler Gewinn 3: " << result3 << "\n";

    return 0;
}
