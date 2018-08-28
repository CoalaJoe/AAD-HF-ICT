#include <iostream>
#include "Dicer.h"

int Dicer::roll()
{
    int num, sides, sum = 0;
    std::cout << "Enter a throw: ";
    scanf("%dd%d", &num, &sides);

    for (int i = 0; i < num; ++i) {
        sum += rand() % sides + 1;
    }

    std::cout << sum;

    return sum;
}
