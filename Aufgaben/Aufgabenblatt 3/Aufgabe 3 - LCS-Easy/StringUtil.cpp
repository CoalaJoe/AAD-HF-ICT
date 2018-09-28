#include "StringUtil.h"

/**
 * Returns longest common string using the "Dynamic Programming" approach.
 *
 * @param input1
 * @param input2
 * @return
 */
string StringUtil::lcs(string input1, string input2)
{
    auto          map       = new unsigned long *[input1.length()];
    unsigned long maxLength = 0;
    unsigned long i, j;
    std::string   lcs;

    for (i = 0; i < input1.length(); ++i) {
        map[i] = new unsigned long[input2.length()]();
    }

    for (i = 0; i < input1.length(); ++i) {
        for (j = 0; j < input2.length(); ++j) {
            if (tolower(input1.at(i)) == tolower(input2.at(j))) {
                // Update map.
                if (i == 0 || j == 0) {
                    map[i][j] = 1;
                } else {
                    map[i][j] = map[i - 1][j - 1] + 1;
                }
                // Update entry.
                if (map[i][j] > maxLength) {
                    maxLength = map[i][j];
                    lcs       = input1.substr(i - maxLength + 1, maxLength);
                }
            }
        }
    }

    delete[] map;

    return lcs;
}
