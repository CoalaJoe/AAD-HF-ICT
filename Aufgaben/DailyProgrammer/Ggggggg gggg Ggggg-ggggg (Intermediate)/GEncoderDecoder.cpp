#include <iostream>
#include <vector>
#include <map>
#include "GEncoderDecoder.h"

std::string GEncoderDecoder::encode(std::string input)
{
    std::map<std::string, char> encodingTable;

    std::string encodingTableString = input.substr(0, input.find('\n'));
    std::string encodedText         = input.substr(input.find('\n'), input.length());
    std::string decodedString;

    unsigned long i;

    for (i = 0; i < encodingTableString.length(); i += 6) {
        encodingTable[encodingTableString.substr(i + 2, 3)] = input.substr(i, 1)[0];
    }

    for (i = 0; i < encodedText.length(); ++i) {
        if (encodingTable.end() != encodingTable.find(encodedText.substr(i, 3))) {
            decodedString += encodingTable[encodedText.substr(i, 3)];
            i += 2;
        } else {
            decodedString += encodedText.at(i);
        }
    }

    std::cout << decodedString;

    return decodedString;
}
