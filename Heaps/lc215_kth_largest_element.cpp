#include "../include/standard.h"
using namespace std;

/*
    LeetCode 215: Kth Largest Element in an Array

    Approach: keep a min-heap containing the k largest values seen so far.
    The heap has at most k elements, so its top is the smallest of those k
    values, which is exactly the k-th largest value after all inputs are read.

    Example: nums = [3, 2, 1, 5, 6, 4], k = 2 -> 5

    Time: O(n log k)     Space: O(k)
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int value : nums) {
            minHeap.push(value);
            if (static_cast<int>(minHeap.size()) > k) {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    Solution solution;
    cout << "The " << k << "-th largest value is "
         << solution.findKthLargest(nums, k) << endl;
    return 0;
}
