#include "Message.h"

const std::string &Message::getValue() const
{
    return value;
}

void Message::setValue(const std::string &value)
{
    Message::value = value;
}

int Message::getClassification() const
{
    return classification;
}

void Message::setClassification(int classification)
{
    Message::classification = classification;
}
