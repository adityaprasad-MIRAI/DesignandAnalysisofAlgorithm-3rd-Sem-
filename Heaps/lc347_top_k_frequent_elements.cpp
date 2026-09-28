#include "../include/standard.h"
using namespace std;

/*
    LeetCode 347: Top K Frequent Elements

    Approach:
    1. Count each value with an unordered_map.
    2. Keep a min-heap of (frequency, value) pairs with at most k entries.
       If the heap grows beyond k, remove the least frequent entry.
    3. The heap now contains the k most frequent values. Their output order
       does not matter for this problem.

    Example: nums = [1, 1, 1, 2, 2, 3], k = 2 -> [1, 2]

    Time: O(n + m log k)     Space: O(m + k)
    n is the number of values and m is the number of distinct values.
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        for (int value : nums) {
            ++frequency[value];
        }

        if (k <= 0 || k > static_cast<int>(frequency.size())) {
            return {};
        }

        using FrequencyValue = pair<int, int>;
        priority_queue<FrequencyValue, vector<FrequencyValue>,
                       greater<FrequencyValue>> minHeap;

        for (const auto& entry : frequency) {
            minHeap.push({entry.second, entry.first});
            if (static_cast<int>(minHeap.size()) > k) {
                minHeap.pop();
            }
        }

        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    Solution solution;
    vector<int> result = solution.topKFrequent(nums, k);

    cout << "Top " << k << " frequent values: ";
    for (int value : result) {
        cout << value << ' ';
    }
    cout << endl;
    return 0;
}
