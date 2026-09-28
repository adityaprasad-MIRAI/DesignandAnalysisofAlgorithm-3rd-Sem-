#include "../include/standard.h"
using namespace std;

/*
    LeetCode 974: Subarray Sums Divisible by K

    Two prefix sums form a subarray divisible by k when their remainders modulo
    k are equal. Count each normalized remainder as the prefix sums are read;
    every earlier matching remainder creates one valid subarray. Normalizing
    with ((remainder % k) + k) % k handles negative array values correctly.

    Time: O(n) average     Space: O(min(n, k))
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<long long, int> remainderFrequency;
        remainderFrequency[0] = 1;

        long long prefixSum = 0;
        int subarrayCount = 0;
        for (int value : nums) {
            prefixSum += value;
            long long remainder = ((prefixSum % k) + k) % k;
            subarrayCount += remainderFrequency[remainder];
            ++remainderFrequency[remainder];
        }
        return subarrayCount;
    }
};

int main() {
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    Solution solution;
    cout << "Subarrays divisible by " << k << ": "
         << solution.subarraysDivByK(nums, k) << endl;
    return 0;
}
