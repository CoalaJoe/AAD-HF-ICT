/**
 * Simple Challange from: https://www.reddit.com/r/dailyprogrammer/comments/8s0cy1/20180618_challenge_364_easy_create_a_dice_roller/
 */

#include <iostream>
#include "Utils/Dicer.h"

int main()
{
    Dicer dicer;
    std::cout
            << "The first number is the number of dice to roll, \n"
            << "the d just means \"dice\", it's just used to split up the two numbers, \n"
            << "and the second number is how many sides the dice have. \n"
            << "So the above example of \"3d6\" means \"roll 3 6-sided dice\".\n\n";

    dicer.roll();

    return 0;
}