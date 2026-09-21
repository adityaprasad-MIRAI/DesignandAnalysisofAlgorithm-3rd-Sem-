#include "standard.h"
using namespace std;

/*
    Problem: Two Sum
    ---------------
    Find the indices of two numbers in the array that add up to a target.

    Idea:
    - While scanning the array, store each number with its index in a hash map.
    - For the current number, check whether the complement (target - current) has
      already been seen before.

    Example:
    Input: nums = [2, 7, 11, 15], target = 9
    Output: 0 1
    because 2 + 7 = 9.
*/

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    unordered_map<int, int> seenIndex;

    bool found = false;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        // If the complement was seen earlier, we have the answer.
        if (seenIndex.count(complement) > 0) {
            cout << "Indices: " << seenIndex[complement] << " and " << i << endl;
            cout << "Values: " << nums[seenIndex[complement]] << " and " << nums[i] << endl;
            found = true;
            break;
        }

        seenIndex[nums[i]] = i;
    }

    if (!found) {
        cout << "No pair found for the target." << endl;
    }

    return 0;
}