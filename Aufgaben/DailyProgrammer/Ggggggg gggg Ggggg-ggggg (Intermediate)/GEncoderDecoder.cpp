#include <iostream>
#include <vector>
#include <map>
#include "GEncoderDecoder.h"

std::string GEncoderDecoder::decode(std::string input)
{
    std::map<std::string, char> encodingTable;

    std::string encodingTableString = input.substr(0, input.find('\n'));
    std::string encodedText         = input.substr(input.find('\n'), input.length());
    std::string encodingTableSubString;
    std::string decodedString;

    unsigned long i, space_counter  = 0, last_match = 0;


    for (i = 0; i < encodingTableString.length(); ++i) {
        if ((encodingTableString.at(i) == ' ' && ++space_counter % 2 == 0) || i + 1 == encodingTableString.length()) {
            if (i + 1 == encodingTableString.length()) {
                ++i;
            }
            encodingTableSubString = encodingTableString.substr(last_match, i - last_match);
            ++i;
            last_match = i;

            encodingTable[encodingTableSubString.substr(2, encodingTableSubString.length() -
                                                           2)] = encodingTableSubString.substr(0, 1)[0];
        }
    }

    for (i = 0; i < encodedText.length(); ++i) {
        for (auto c : encodingTable) {
            if (c.first.length() < encodedText.length() - i) {
                if (c.first == encodedText.substr(i, c.first.length())) {
                    decodedString += c.second;
                    i += c.first.length() - 1;
                    goto outer;
                }
            }
        }
        decodedString += encodedText.at(i);
        outer:;
    }

    std::cout << decodedString;

    return decodedString;
}

