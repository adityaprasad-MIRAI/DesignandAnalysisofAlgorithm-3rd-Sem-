#include "../include/standard.h"
using namespace std;

/*
    Problem: Binary-search a target in a sorted vector with lower_bound
    -------------------------------------------------------------------
    lower_bound returns the first element in the sorted range that is not less than target.

    If we want to find whether a value exists, we can compare the returned iterator with end().

    Example:
    Input: nums = [1, 3, 5, 7, 9], target = 7
    Output: Found at index 3
*/

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11, 13};
    int target = 7;

    // lower_bound searches the first position where value >= target.
    auto it = lower_bound(nums.begin(), nums.end(), target);

    cout << "Sorted vector: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Target: " << target << endl;

    if (it != nums.end() && *it == target) {
        cout << "Found at index: " << (it - nums.begin()) << endl;
    } else {
        cout << "Target not found. lower_bound points to first value >= target at index: "
             << (it - nums.begin()) << endl;
    }

    return 0;
}
