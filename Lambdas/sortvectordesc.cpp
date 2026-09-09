// sort_descending.cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers = {15, 3, 22, 8, 41, 10};

    // std::sort with an inline custom lambda comparator for descending order.
    // The lambda returns true if the first argument should strictly precede the second.
    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a > b;
    });

    cout << "Sorted in descending order: ";
    for (const int& num : numbers) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}