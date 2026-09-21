#include "../include/standard.h"
using namespace std;

/*
    Problem: Count distinct elements using sort + unique
    ----------------------------------------------------
    Suppose we have a vector with repeated values.
    To count distinct elements:
    1. Sort the vector.
    2. Use unique() to move duplicates together.
    3. The distance between begin() and the returned iterator gives the count.

    Example:
    Input: [4, 2, 2, 7, 4, 1, 7, 3]
    Output: 5 distinct elements
*/

int main() {
    vector<int> nums = {4, 2, 2, 7, 4, 1, 7, 3};

    cout << "Original array: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    // Step 1: sort the numbers so equal values come together.
    sort(nums.begin(), nums.end());

    cout << "After sorting: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    // Step 2: unique() moves duplicates to the end and returns iterator to first duplicate.
    auto last = unique(nums.begin(), nums.end());

    // Step 3: count elements before the duplicate region.
    int distinctCount = distance(nums.begin(), last);

    cout << "Distinct elements count: " << distinctCount << endl;

    cout << "Distinct values: ";
    for (auto it = nums.begin(); it != last; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
