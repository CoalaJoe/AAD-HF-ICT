#ifndef TEST_2016_OKTOBER_MESSAGE_H
#define TEST_2016_OKTOBER_MESSAGE_H

#include <string>

class Message {
private:
    std::string value;
    int         classification;
public:
    const std::string &getValue() const;

    void setValue(const std::string &value);

    int getClassification() const;

    void setClassification(int classification);
};


#endif //TEST_2016_OKTOBER_MESSAGE_H
