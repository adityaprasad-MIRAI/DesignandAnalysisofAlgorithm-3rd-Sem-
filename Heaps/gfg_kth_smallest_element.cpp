#include "../include/standard.h"
using namespace std;

/*
    GeeksforGeeks: Kth Smallest Element

    Approach: keep a max-heap containing the k smallest values seen so far.
    When the heap grows beyond k, remove its largest value. At the end, the
    largest value among the k smallest is at the top, so it is the k-th smallest.

    Example: arr = [7, 10, 4, 3, 20, 15], k = 3 -> 7

    Time: O(n log k)     Space: O(k)
*/
class Solution {
public:
    int kthSmallest(vector<int>& arr, int k) {
        priority_queue<int> maxHeap;

        for (int value : arr) {
            maxHeap.push(value);
            if (static_cast<int>(maxHeap.size()) > k) {
                maxHeap.pop();
            }
        }

        return maxHeap.top();
    }
};

int main() {
    vector<int> values = {7, 10, 4, 3, 20, 15};
    int k = 3;

    Solution solution;
    cout << "The " << k << "-th smallest value is "
         << solution.kthSmallest(values, k) << endl;
    return 0;
}
