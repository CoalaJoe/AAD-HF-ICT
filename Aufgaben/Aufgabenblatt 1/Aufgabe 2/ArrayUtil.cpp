#include "ArrayUtil.h"
#include <iostream>

long *ArrayUtil::multiplyArrayValues(const long *values, const int ARRAY_SIZE)
{
    long *output = new long[ARRAY_SIZE]; // Create array at runtime.

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        output[i] = 1; // Reset
        for (int j = 0; j < ARRAY_SIZE; ++j) {
            if (j != i) output[i] *= values[j]; // Multiply if is not itself.
        }
    }

    return output;
}
