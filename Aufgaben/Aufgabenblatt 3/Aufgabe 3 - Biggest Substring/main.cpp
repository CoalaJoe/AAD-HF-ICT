/**
 * In dieser Aufgabe soll eine Methode implementiert werden, welche von 2 Zeichenketten den längsten Substring findet,
 * welcher in beiden Zeichenketten vorkommt
 *
 * https://www.sanfoundry.com/cpp-program-implement-suffix-tree/
 */

#include <iostream>
#include "SuffixTree.h"

int main()
{
    std::string s1, s2;
    std::cout << "Finding longest common substring using suffix trees\n";
    std::cout << "Enter 1st String: ";
    std::cin >> s1;
    std::cout << "Enter 2nd String: ";
    std::cin >> s2;
    SuffixTree st;
    st.findLCS(s1, s2);
    return 0;
}
