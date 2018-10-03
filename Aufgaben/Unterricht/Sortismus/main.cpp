#include <iostream>
#include <vector>
#include <ctime>
#include "Sort.h"
#include "InsertionSort.h"

std::vector<int> randomValue(int n)
{
    std::vector<int> vector;
    // srand(static_cast<unsigned int>(time(nullptr)));
    vector.reserve(n);
    for (int i = 0; i < n; ++i) {
        vector.push_back(rand() % 1000);
    }

    return vector;
}

int main()
{
    std::vector<int> testSet1 = randomValue(10);
    clock_t          start, stop;

    Sort *s = new InsertionSort();
    start = clock();
    s->sort(testSet1);
    stop = clock();

    std::cout << "Time using insertion Sort: " << (double) (stop - start) / CLOCKS_PER_SEC << " seconds.";

    for (auto v : testSet1) {
        std::cout << v << ", ";
    }
    std::cout << "\n";

    return 0;
}
