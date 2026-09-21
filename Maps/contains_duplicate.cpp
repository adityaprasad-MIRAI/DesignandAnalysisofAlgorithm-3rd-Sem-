#include "standard.h"
using namespace std;

/*
    Problem: Contains Duplicate
    ---------------------------
    Given a list of numbers, check whether any value appears at least twice.

    Idea:
    - Use an unordered_map to store how many times each number has appeared.
    - If a number is seen again, we immediately know the answer is true.

    Example:
    Input: [1, 2, 3, 4, 2]
    Output: true
*/

int main() {
    vector<int> nums = {1, 2, 3, 4, 2};

    unordered_map<int, int> freq;

    bool hasDuplicate = false;

    for (int x : nums) {
        freq[x]++;

        // If this number appears more than once, duplicate found.
        if (freq[x] > 1) {
            hasDuplicate = true;
            break;
        }
    }

    cout << "Numbers: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Contains duplicate? " << (hasDuplicate ? "true" : "false") << endl;

    return 0;
}