#include <iostream>
#include <string>
#include "GEncoderDecoder.h"

int main()
{
    std::string input1  = "H GgG d gGg e ggG l GGg o gGG r Ggg w ggg\nGgGggGGGgGGggGG, ggggGGGggGGggGg!";
    std::string result1 = "Hello, world!";
    std::string input2  = "a GgG d GggGg e GggGG g GGGgg h GGGgG i GGGGg l GGGGG m ggg o GGg p Gggg r gG y ggG\nGGGgGGGgGGggGGgGggG /gG/GggGgGgGGGGGgGGGGGggGGggggGGGgGGGgggGGgGggggggGggGGgG!";
    std::string result2 = "hooray /r/dailyprogrammer!";

    if (result1 == GEncoderDecoder::decode(input1)) {}

    if (result2 == GEncoderDecoder::decode(input2)) {
        std::cout << "Success";
    }

    return 0;
}