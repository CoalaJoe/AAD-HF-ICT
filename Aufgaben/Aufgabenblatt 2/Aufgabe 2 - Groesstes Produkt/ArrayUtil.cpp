#include "ArrayUtil.h"
#include <algorithm>
#include <iostream>
#include <vector>

/**
 * Returns biggest possible product from given integers.
 *
 * @param values
 * @param ARRAY_SIZE
 * @return
 */
int ArrayUtil::highestProduct(int *values, const int ARRAY_SIZE)
{
    if (ARRAY_SIZE < 3) {
        exit(1);
    }
    int i;
    int productOfSmallest = 1, productOfBiggest = 1;

    // negativeNumbers also contain 0.
    std::vector<int> positiveNumbers, negativeNumbers;

    // Order descending.
    std::sort(values, values + ARRAY_SIZE);
    std::cout << "\nTestset: ";
    for (i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << values[i] << ", ";
    }
    std::cout << "\n";

    for (i = 0; i < ARRAY_SIZE; ++i) {
        if (values[i] > 1) {
            positiveNumbers.push_back(values[i]);
        } else {
            negativeNumbers.push_back(values[i]);
        }
    }

    // Less than 2 negative numbers
    if (negativeNumbers.size() <= 1) {
        return values[ARRAY_SIZE - 1] * values[ARRAY_SIZE - 2] * values[ARRAY_SIZE - 3];
    } else { // More than 1 negative number
        if (positiveNumbers.empty()) { // If there are no positive numbers
            if (values[0] == 0) { // If biggest number is 0.
                return 0;
            } else {
                return values[ARRAY_SIZE - 1] * values[ARRAY_SIZE - 2] * values[ARRAY_SIZE - 3];
            }
        }

        // Calculate the biggest product of positive and negative.
        productOfBiggest = positiveNumbers.at(positiveNumbers.size() -1) * positiveNumbers.at(positiveNumbers.size() - 2);
        productOfSmallest = negativeNumbers.at(negativeNumbers.size() -1) * negativeNumbers.at(negativeNumbers.size() - 2);

        if (productOfBiggest > productOfSmallest) {
            return values[ARRAY_SIZE - 1] * values[ARRAY_SIZE - 2] * values[ARRAY_SIZE - 3];
        } else {
            return productOfSmallest * values[ARRAY_SIZE -1];
        }
    }
}
