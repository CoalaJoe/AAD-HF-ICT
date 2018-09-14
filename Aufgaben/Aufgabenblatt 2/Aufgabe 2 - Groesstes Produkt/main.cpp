/**
 * In dieser Aufgabe soll eine Methode implementiert werden, welche als Parameter einen Array mit Integer Werten enthält.
 * Aus diesem Array soll nun das grösste Produkt gefunden werden, welches mit 3 Elementen aus diesem Array erstellt werden kann.
 */

#include <iostream>
#include "ArrayUtil.h"

int main()
{
    int set1[9] = { 3,  4,  5,  6,  7,  8,  9,  10,  11};
    int set2[9] = { 3,  4,  5,  6,  7,  8,  9,  10, -11};
    int set3[9] = { 3,  4,  5,  6,  7,  8,  9, -10, -11};
    int set4[9] = {-3, -4, -5, -6, -7, -8, -9, -10, -11};
    int set5[9] = { 0, -4, -5, -6, -7, -8, -9, -10, -11};

    int result1;
    int result2;
    int result3;
    int result4;
    int result5;

    // Should return: 990
    result1 = ArrayUtil::highestProduct(set1, 9);
    std::cout << "Result of set 1 is: " << result1 << "\n\n";
    std::cout << "-----------------------------------------------\n";

    // Should return: 720
    result2 = ArrayUtil::highestProduct(set2, 9);
    std::cout << "Result of set 2 is: " << result2 << "\n\n";
    std::cout << "-----------------------------------------------\n";

    // Should return: 990
    result3 = ArrayUtil::highestProduct(set3, 9);
    std::cout << "Result of set 3 is: " << result3 << "\n\n";
    std::cout << "-----------------------------------------------\n";

    // Should return: -60
    result4 = ArrayUtil::highestProduct(set4, 9);
    std::cout << "Result of set 4 is: " << result4 << "\n\n";
    std::cout << "-----------------------------------------------\n";

    // Should return: 0
    result5 = ArrayUtil::highestProduct(set5, 9);
    std::cout << "Result of set 5 is: " << result5 << "\n\n";

    return 0;
}