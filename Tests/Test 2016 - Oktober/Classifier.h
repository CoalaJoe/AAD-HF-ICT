#ifndef TEST_2016_OKTOBER_CLASSIFIER_H
#define TEST_2016_OKTOBER_CLASSIFIER_H

#include <string>
#include "Message.h"

class Classifier {
public:
    static Message *classifyMessages(std::string *messages, int size);
};


#endif //TEST_2016_OKTOBER_CLASSIFIER_H
