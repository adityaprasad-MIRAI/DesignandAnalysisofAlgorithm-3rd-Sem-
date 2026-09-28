#include "../include/standard.h"
using namespace std;

/*
    LeetCode 560: Subarray Sum Equals K

    A running prefix sum P[j] minus an earlier prefix sum P[i] equals the sum
    of subarray (i, j]. Therefore, at each position, count how many previous
    prefix sums equal currentPrefix - k. Store prefix-sum frequencies in a hash
    map; seed sum 0 with frequency 1 to count subarrays starting at index 0.

    Time: O(n) average     Space: O(n)
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> prefixFrequency;
        prefixFrequency[0] = 1;

        long long prefixSum = 0;
        int subarrayCount = 0;
        for (int value : nums) {
            prefixSum += value;
            auto match = prefixFrequency.find(prefixSum - k);
            if (match != prefixFrequency.end()) {
                subarrayCount += match->second;
            }
            ++prefixFrequency[prefixSum];
        }
        return subarrayCount;
    }
};

int main() {
    vector<int> nums = {1, 1, 1};
    int k = 2;

    Solution solution;
    cout << "Subarrays with sum " << k << ": "
         << solution.subarraySum(nums, k) << endl;
    return 0;
}
