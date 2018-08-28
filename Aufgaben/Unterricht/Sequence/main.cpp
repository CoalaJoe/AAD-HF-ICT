#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class FastaReader {
public:
    static string read(const string &file, bool &success);
};

string FastaReader::read(const string &file, bool &success)
{
    ifstream fs(file);
    if (!fs) {
        success = false;
        return "";
    }
    success = true;
    string result = "", line;
    while (getline(fs, line)) {
        if (line.at(0) != '>') {
            result += line;
        }
    }
    return result;
}

char analyzeSequence(string sequence)
{
    std::map<char, long> values;
    char                 tmp;

    for (int i = 0; i < sequence.length(); ++i) {
        tmp = sequence[i];
        values[tmp]++;
    }

    char biggest_char = values.begin()->first;
    long biggest_int  = values.begin()->second;
    for (auto const&[key, val] : values) {
        if (biggest_int < val) {
            biggest_char = key;
            biggest_int  = val;
        }
    }

    std::cout << biggest_char << ": " << biggest_int << "\n";

    return biggest_char;
}


int main(int argc, char **argv)
{

    // TASKS
    // 1. Read the sample.fa file
    bool    success;
    clock_t start, stop;
    string  fileContents, masterContents;
    fileContents = FastaReader::read("/Users/ashura/Documents/Projects/HF-ICT/AAD/Aufgaben/Sequence/data/sample.fa",
                                     success);

    // 2. Print the length of the sample sequence
    std::cout << "Length: " << fileContents.length() << "\n";

    // 3. Implement the method analyzeSequence and find out which nucleotide
    //    appears most
    analyzeSequence(fileContents);

    // 4. Read the Human Chromosome 1 Sequence (download the file from NCBI)
    masterContents = FastaReader::read("/Users/ashura/Documents/Projects/HF-ICT/AAD/Aufgaben/Sequence/data/master.fa",
                                       success);

    // 5. Print the length of the sequence
    std::cout << "Length: " << masterContents.length() << "\n";

    // 6. Run your algorithm on the human sequence
    start = clock();
    analyzeSequence(masterContents);
    stop = clock();

    double time = (double) (stop - start) / CLOCKS_PER_SEC;
    std::cout << time << "sek";

    return 0;
}
