#include <iostream>
#include "Classifier.h"

int main()
{
    // Runtime O(n^2)
    std::string input[] = {"sales", "hallo martin, alles klar", "marketing", "brand new dvd...", "marketing",
                           "friday appointment"};

    auto *result = Classifier::classifyMessages(input, 6);

    for (int i = 0; i < 6; ++i) {
        std::cout << result[i].getClassification() << ": " << result[i].getValue() << "\n";
    }

    return 0;
}