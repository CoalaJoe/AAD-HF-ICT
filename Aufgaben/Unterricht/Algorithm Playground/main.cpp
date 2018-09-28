#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v;
    v.reserve(1000);

    for (int i = 0; i < 10000; ++i) {
        v.push_back(rand() % 10000);
    }
    sort(v.begin(), v.end());
    auto it = unique(v.begin(), v.end());
    v.resize(static_cast<unsigned long>(distance(v.begin(), it)));

    std::cout << "Amount of unique numbers: " << v.size();

    return 0;
}