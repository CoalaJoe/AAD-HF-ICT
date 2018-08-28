#ifndef SEQUENCE_RANDOMDATAUTIL_H
#define SEQUENCE_RANDOMDATAUTIL_H


#include <string>

class RandomDataUtil {
    std::string m(std::string s)
    {
        bool found;
        char ch, tmpCh;

        for (std::string::size_type i = 0; i < s.size(); ++i) {
            ch    = s[i];
            found = false;
            for (std::string::size_type j = i+1; j < s.size(); ++j) {
                tmpCh = s[j];
                if (tmpCh == ch) {
                    found = true;
                    s.erase(j, 1);
                }
            }

            if (!found) {
                std::string result(1, ch);

                return result;
            }
        }

        return "_";
    }
};


#endif //SEQUENCE_RANDOMDATAUTIL_H
