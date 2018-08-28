#include <iostream>
#include <ctime>

int main()
{
    const int N       = 60000;
    auto      *values = new int[N];
    auto      *result = new int[N];
    clock_t   start, stop;

    for (int i = 0; i < N; ++i) {
        values[i] = rand() % 10;
    }
    start = clock();
    for (int i = 0; i < N; ++i) {
        int      sum = 0;
        for (int j   = i; j < N; ++j) {
            sum += values[j];
        }
        result[i] = sum;
    }
    stop = clock();
    double time = (double) (stop - start) / CLOCKS_PER_SEC;
    std::cout << time << "sek";

    return 0;
}