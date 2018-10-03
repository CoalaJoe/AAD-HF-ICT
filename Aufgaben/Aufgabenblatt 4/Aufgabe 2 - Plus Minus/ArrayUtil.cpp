#include <iostream>
#include "ArrayUtil.h"

Result ArrayUtil::analyzeArray(vector<int> input)
{
    auto result = Result();

    for (auto i : input) {
        if (i < 0) {
            ++result.nNegative;
        } else if (i > 0) {
            ++result.nPositive;
        } else {
            ++result.nZero;
        }
    }

    printf(
            "nPositive: %.1f%%; nZero %.1f%%; nNegative %.1f%%",
            (100. / input.size() * result.nPositive),
            (100. / input.size() * result.nZero),
            (100. / input.size() * result.nNegative)
    );

    return result;
}
