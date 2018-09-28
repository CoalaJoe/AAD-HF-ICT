#include <iostream>
#include <vector>
#include <list>
#include <ctime>

using namespace std;

int main()
{
    vector<int> v;
    list<int>   l;
    clock_t     start, stop;
    const int   N = 10000000;

    srand(10);
    start = clock();
    for (int i = 0; i < N; ++i) {
        l.push_back(rand());
    }
    stop = clock();
    std::cout << "List Push: \t" << (double) (stop - start) / CLOCKS_PER_SEC << "\n";

    srand(10);
    start = clock();
    for (int i = 0; i < N; ++i) {
        v.push_back(rand());
    }
    stop = clock();
    std::cout << "Vector Push: \t" << (double) (stop - start) / CLOCKS_PER_SEC << "\n";
    
    std::cout << "\n";

    start = clock();
    for (int i = 0; i < 10000; ++i) {
        l.insert(l.begin(), 0);
    }
    stop = clock();
    std::cout << "List Insert: \t" << (double) (stop - start) / CLOCKS_PER_SEC << "\n";


    start = clock();
    for (int i = 0; i < 10000; ++i) {
        v.insert(v.begin(), 0);
    }
    stop = clock();
    std::cout << "Vector Insert: \t" << (double) (stop - start) / CLOCKS_PER_SEC << "\n";


    return 0;
}