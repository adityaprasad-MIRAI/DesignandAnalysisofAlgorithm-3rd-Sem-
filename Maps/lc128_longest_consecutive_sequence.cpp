#include "../include/standard.h"
using namespace std;

/*
    LeetCode 128: Longest Consecutive Sequence

    Put all values in a hash set. Only start counting from values that have no
    predecessor in the set, so each consecutive run is traversed once instead
    of restarting from every element. Use a wider integer for neighbor checks
    to avoid overflow at the int limits.

    Time: O(n) average     Space: O(n)
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> values(nums.begin(), nums.end());
        int longestLength = 0;

        for (int value : values) {
            long long previous = static_cast<long long>(value) - 1;
            if (previous >= INT_MIN && values.count(static_cast<int>(previous))) {
                continue;
            }

            int runLength = 1;
            long long next = static_cast<long long>(value) + 1;
            while (next <= INT_MAX && values.count(static_cast<int>(next))) {
                ++runLength;
                ++next;
            }
            longestLength = max(longestLength, runLength);
        }
        return longestLength;
    }
};

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    Solution solution;
    cout << "Longest consecutive sequence length: "
         << solution.longestConsecutive(nums) << endl;
    return 0;
}
