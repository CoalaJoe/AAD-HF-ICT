/**
 * Aufgabe 1. Analyse
 *
 * Welche Laufzeit hat der folgende Code?
 *
 * 2 * O(N)
 *
 * Lösung: O(2*N)
 */

#include <iostream>

void foo(int *array, int size)
{
    int sum     = 0;
    int product = 1;

    // O(N)
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    // O(N)
    for (int i = 0; i < size; i++) {
        product *= array[i];
        std::cout << sum << "," << product << std::endl;
    }
}

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}