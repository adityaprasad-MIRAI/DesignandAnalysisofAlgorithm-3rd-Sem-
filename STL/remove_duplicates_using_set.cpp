#include <iostream>
#include <set>
#include<unordered_set>
#include <vector>

using namespace std;


int main() {
    vector<int> numbers = {4, 2, 7, 2, 4, 9, 7, 1};

    // An unordered_set also stores each value only once, but does not sort values.
    unordered_set<int> uniqueNumbersUnordered(numbers.begin(), numbers.end());

    cout << "Vector after removing duplicates using unordered_set: ";
    for (int number : uniqueNumbersUnordered) {
        cout << number << ' ';
    }
    cout << "\n(Note: unordered_set does not guarantee the output order.)\n";

    // A set stores each value only once and keeps values sorted.
    set<int> uniqueNumbers(numbers.begin(), numbers.end());

    cout << "Vector after removing duplicates: ";
    for (int number : uniqueNumbers) {
        cout << number << ' ';
    }
    cout << '\n';

    

    return 0;
}
