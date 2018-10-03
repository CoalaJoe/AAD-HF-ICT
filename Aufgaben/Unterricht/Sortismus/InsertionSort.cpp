#include <iostream>
#include "InsertionSort.h"

void InsertionSort::sort(std::vector<int> &v)
{
    unsigned long i, j;
    int           tmp;

    for (i = 1; i < v.size(); ++i) {
        for (j = 0; j < i; ++j) {
            if (v.at(i) < v.at(j)) { // Newly picked up is smaller as current in sorted.
                if (v.at(i) < v.at(j)) {
                    // TODO: Fix this mess.
                    tmp = v.at(j);
                    v.at(j) = v.at(i);
                    v.at(i) = tmp;
                }
                if (j == i - 1) { // There was no bigger number. Do Nothing. It is already at the next place.
                    continue;
                }
            }
        }
    }
}
