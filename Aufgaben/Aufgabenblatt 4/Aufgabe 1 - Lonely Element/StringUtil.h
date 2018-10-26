#ifndef AUFGABE_1_LONELY_ELEMENT_STRINGUTIL_H
#define AUFGABE_1_LONELY_ELEMENT_STRINGUTIL_H

#include <string>

using namespace std;

class StringUtil {
public:
    static char getLonelyElement(string input);
    static char32_t getLonelyElement(u32string input);
};


#endif //AUFGABE_1_LONELY_ELEMENT_STRINGUTIL_H
