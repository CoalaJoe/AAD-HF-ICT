/*
Klausur 10.DEC.2016, Algorithmen und Datenstrukturen
Name:
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// Aufgabe 1
int biggestDigit(int value)
{
    // Diese Methode bekommt einen Wert (value) als Parameter.
    // Von dieser Zahl soll die groesste Ziffer ermittelt werden.
    // Bsp: 53758 (Das Resultat ist 8)
    char      biggest = 0;
    for (char &c : std::to_string(value)) {
        if ((int) c > (int) biggest) {
            biggest = c;
        }
    }


    return (int) biggest - 48;
}

void testBiggestDigit()
{
    // test code
    cout << "Test Aufgabe 1" << endl;
    cout << (biggestDigit(23957) == 9 ? "TRUE" : "FALSE") << endl;
    cout << (biggestDigit(42958) != 2 ? "TRUE" : "FALSE") << endl;
    cout << (biggestDigit(07) == 7 ? "TRUE" : "FALSE") << endl;
    cout << (biggestDigit(31) != 1 ? "TRUE" : "FALSE") << endl;
    cout << "***" << endl;
}

// Aufgabe 2
struct Data {
    int value;
};

list<int> getPeakValues(vector<Data> data)
{
    // Diese Methode bekommt eine Liste von Integer Werten. In dieser
    // Liste sollen alle Peak werden gefunden werden. Ein Wert ist
    // ein Peak Wert, falls die Werte vorher (falls existent) und
    // nachher (falls existent) kleiner sind.
    // Bsp: 4, 2, 9, 10, 4 (die erste Zahl ist ein Peak Wert, sowie die 9)

    list<int> peaks;

    for (unsigned long i = 0; i < data.size(); ++i) {
        auto d = data.at(i);
        if (i != 0) {
            if (data.at(i - 1).value > d.value) { // Value before is bigger.
                continue;
            }
        }

        if (i != data.size()) {
            if (data.at(i + 1).value > d.value) { // Value after is bigger.
                continue;
            }
        }

        peaks.push_back(d.value);
    }

    return peaks;
}

void testGetPeakValues()
{
    vector<Data> testValues;
    int          v[]    = {40, 10, 20, 5, 45, 50, 65, 90, 35, 25};
    for (int     i      = 0; i < 10; i++) {
        Data d;
        d.value = v[i];
        testValues.push_back(d);
    }
    list<int>    result = getPeakValues(testValues);
    cout << "Test Aufgabe 2" << endl;
    cout << (result.size() == 3 ? "TRUE" : "FALSE") << endl;
    cout << (find(result.begin(), result.end(), 40) != result.end() ? "TRUE" : "FALSE") << endl;
    cout << (find(result.begin(), result.end(), 20) != result.end() ? "TRUE" : "FALSE") << endl;
    cout << (find(result.begin(), result.end(), 90) != result.end() ? "TRUE" : "FALSE") << endl;
    cout << "***" << endl;
}

// Aufgabe 3
struct ListElement {
    int         value;
    ListElement *nextElement;
};

struct LinkedList {
    ListElement *root;

    bool hasLoop()
    {
        // Diese Methode stellt fest, ob es in der Liste einen
        // Loop gibt, d.h. ob ein Element auf ein vorheriges in
        // Liste zeigt. Falls ja gibt die Methode true zurueck.
        // Verwenden Sie einen geeigneten STL Container um
        // festzustellen, ob ein solcher Loop existiert.

        // IMPORTANT: The test doesn't test the function properly. true = false; false = true.

        auto node = root;

        vector<ListElement *> addresses;
        while (node->nextElement != nullptr) {
            if (std::find(addresses.begin(), addresses.end(), node) != addresses.end()) {
                return false;
            }
            addresses.push_back(node);
            node = node->nextElement;
        }

        return true;
    }
};

void testHasLoop()
{
    LinkedList  l;
    ListElement *elements = new ListElement[10];
    for (int    i         = 0; i < 10; i++) {
        elements[i].value                   = rand();
        if (i == 9) elements[i].nextElement = 0;
        else elements[i].nextElement = &elements[i + 1];
    }
    l.root                = &elements[0];
    cout << "Test Aufgabe 3" << endl;
    cout << (l.hasLoop() ? "TRUE" : "FALSE") << endl;
    elements[8].nextElement = &elements[2];
    cout << (l.hasLoop() ? "FALSE" : "TRUE") << endl;
    cout << "***" << endl;
}


int main(int argc, char **argv)
{

    testBiggestDigit();
    testGetPeakValues();
    testHasLoop();

    return 0;
}
