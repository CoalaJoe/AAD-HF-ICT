#include<iostream>
#include<cmath>
#include<vector>
#include"KlausurUtils.h"

using namespace std;

static const bool EXECUTE_PERFORMANCE_TEST_AUFGABE1 = true;

string aufgabe1_data    = "Aufgabe1.dat";
string aufgabe1_samples = "Aufgabe1_Samples.dat";
string aufgabe2_data    = "Aufgabe2.dat";
string aufgabe2_results = "Aufgabe2_Results.dat";

auto getDataAufgabe1(int idx)
{
    return KlausurUtils::getData(idx, aufgabe1_data);
}

auto methodeAufgabe1(int loadRecordsQty, int value)
{
    vector<long> dataset;
    dataset.reserve(loadRecordsQty);

    for (long i = 0; i < loadRecordsQty; ++i) {
        dataset.push_back(getDataAufgabe1(i));
    }

    for (auto d : dataset) {
        if (d % value == 0) {
            return true;
        }
    }

    return false;
}

auto methodeAufgabe2(int n)
{
    // IMPLEMENT YOUR SOLUTION HERE
    return 1;
}

int main()
{
    // Access all Files one time to have the data cached
    getDataAufgabe1(0);
    // Variables used later
    bool calculatedBoolResult;

    /*********************************************************
     * Aufgabe 1
     *
     * Implementieren Sie die oben vorbereitete Funktion "methodeAufgabe1()"
     *
     * Parameter:
     * #1 - loadRecordsQty - Gibt an wie viele Datensätze Sie verarbeiten müssen
     * #2 - value - Gesuchter Faktor
     *
     * Aufgabe:
     *
     * Überführen Sie die Daten aus dem File "Aufgabe1.dat" in einen STL Container
     * Ihrer Wahl.
     * Sie können mit der bereitgestellten Methode getDataAufgabe1(int idx) jeweils
     * einen einzelnen Datensatz im File abrufen.
     *
     * Prüfen Sie nun saemtliche geladenen Werte auf folgendes Kriterium hin:
     *
     * Ist der Uebergabewert value ein Faktor von einer der geladenen Zahlen.
     *
     * Bsp. Prüfwert aus dem File = 88
     *      Value = 22
     *
     *      22 x 4 = 88
     *
     *********************************************************/

    cout << "AUFGABE 1 - RESULTATE" << endl;

    // Kleine Datenmenge
    int sampleDataAufgabe1 = KlausurUtils::getData(0, aufgabe1_samples);
    calculatedBoolResult = methodeAufgabe1(100, sampleDataAufgabe1);
    cout << "[CHECK -> " << KlausurUtils::boolToText(calculatedBoolResult)
         << "] - Calculated Result for methodeAufgabe1(" << sampleDataAufgabe1 << ") = '"
         << calculatedBoolResult << "' - Expected Result = '1'" << endl;
    sampleDataAufgabe1   = KlausurUtils::getData(1, aufgabe1_samples);
    calculatedBoolResult = methodeAufgabe1(100, sampleDataAufgabe1);
    cout << "[CHECK -> " << KlausurUtils::boolToText(!calculatedBoolResult)
         << "] - Calculated Result for methodeAufgabe1(" << sampleDataAufgabe1 << ") = '"
         << calculatedBoolResult << "' - Expected Result = '0'" << endl;

    // Grosse Datenmenge (mit Zeitmessung)
    if (EXECUTE_PERFORMANCE_TEST_AUFGABE1) {
        KlausurUtils::startTimer();
        sampleDataAufgabe1   = KlausurUtils::getData(2, aufgabe1_samples);
        calculatedBoolResult = methodeAufgabe1(50000, sampleDataAufgabe1);
        cout << "[CHECK -> " << KlausurUtils::boolToText(calculatedBoolResult)
             << "] - Calculated Result for methodeAufgabe1(" << sampleDataAufgabe1 << ") = '"
             << calculatedBoolResult << "' - Expected Result = '1'" << endl;
        sampleDataAufgabe1   = KlausurUtils::getData(3, aufgabe1_samples);
        calculatedBoolResult = methodeAufgabe1(50000, sampleDataAufgabe1);
        cout << "[CHECK -> " << KlausurUtils::boolToText(!calculatedBoolResult)
             << "] - Calculated Result for methodeAufgabe1(" << sampleDataAufgabe1 << ") = '"
             << calculatedBoolResult << "' - Expected Result = '0'" << endl;
        cout << "Expected Performance = t < 100ms | Effective Time Diff = " << KlausurUtils::stopTimer() << "ms"
             << endl;
    } else {
        cout << " !!! PERFORMANCE TESTS AUFGABE 1 HAS BEEN SKIPPED !!! " << endl;
    }

    /*********************************************************
     * Aufgabe 2
     *
     * Implementieren Sie die oben vorbereitete Funktion "methodeAufgabe2()"
     *********************************************************/

    cout << endl << "AUFGABE 2 - RESULTATE" << endl;

    vector<int> *v = KlausurUtils::getDataVector(aufgabe2_data);
    cout << v->size();

    for (auto it = v->begin(); it < v->end(); it++) {
        int elementIdx = distance(v->begin(), it);
        int result     = methodeAufgabe2(*it);
        if (result == KlausurUtils::getData(elementIdx, aufgabe2_results)) {
            cout << "[CHECK -> PASSED]";
        } else {
            cout << "[CHECK -> FAILED]";
        }
        cout << " - Calculated Result for methodeAufgabe2(" << *it << ") = '" << result << "' - Expected Result = '"
             << KlausurUtils::getData(elementIdx, aufgabe2_results) << "'" << endl;
    }

    return 0;
}