#include <iostream>
#include "Classifier.h"

Message *Classifier::classifyMessages(std::string *messages, int size)
{
    auto *classifiedMessages = new Message[size];

    std::string keyWords[] = {"cash", "subscribe", "marketing"};

    for (int i = 0; i < size; ++i) {
        classifiedMessages[i].setValue(messages[i]);
        int classification = 0;

        // Rule 1
        if (classifiedMessages[i].getValue().size() < 12) {
            ++classification;
        }

        // Rule 2
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                continue;
            }
            if (classifiedMessages[i].getValue() == messages[j]) {
                ++classification;
                break;
            }
        }

        // Rule 3
        for (const auto &k : keyWords) {
            if (classifiedMessages[i].getValue().find(k) != std::string::npos) {
                ++classification;
                break;
            }
        }
        classifiedMessages[i].setClassification(classification);
    }


    return classifiedMessages;
}
