#include "standard.h"
using namespace std;

/*
    Problem: Frequency of Elements
    -----------------------------
    Count how many times each number appears in a vector.

    Example:
    Input: [4, 3, 2, 4, 3, 1, 2, 4]
    Output:
      Frequency of 1: 1
      Frequency of 2: 2
      Frequency of 3: 2
      Frequency of 4: 3
*/

int main() {
    vector<int> nums = {4, 3, 2, 4, 3, 1, 2, 4};

    unordered_map<int, int> frequency;

    // Count each value.
    for (int x : nums) {
        frequency[x]++;
    }

    cout << "Element frequencies:" << endl;
    for (const auto &entry : frequency) {
        cout << "Frequency of " << entry.first << ": " << entry.second << endl;
    }

    return 0;
}