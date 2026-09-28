#include "../include/standard.h"
using namespace std;

/*
    GeeksforGeeks: Largest Subarray with 0 Sum

    If the same prefix sum occurs at indices i and j, the elements between
    them sum to zero. Store only the first index for each prefix sum, because
    the earliest occurrence gives the longest possible subarray ending at the
    current index. A zero prefix sum also describes a zero-sum subarray from
    the beginning of the array.

    Time: O(n) average     Space: O(n)
*/
class Solution {
public:
    int maxLen(vector<int>& arr, int n) {
        unordered_map<long long, int> firstIndex;
        long long prefixSum = 0;
        int longestLength = 0;

        for (int index = 0; index < n; ++index) {
            prefixSum += arr[index];

            if (prefixSum == 0) {
                longestLength = index + 1;
            } else {
                auto first = firstIndex.find(prefixSum);
                if (first != firstIndex.end()) {
                    longestLength = max(longestLength, index - first->second);
                } else {
                    firstIndex[prefixSum] = index;
                }
            }
        }
        return longestLength;
    }
};

int main() {
    vector<int> values = {15, -2, 2, -8, 1, 7, 10, 23};

    Solution solution;
    cout << "Largest zero-sum subarray length: "
         << solution.maxLen(values, static_cast<int>(values.size())) << endl;
    return 0;
}
