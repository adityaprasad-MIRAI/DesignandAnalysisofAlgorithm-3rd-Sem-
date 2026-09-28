#include "../include/standard.h"
using namespace std;

/*
    LeetCode 703: Kth Largest Element in a Stream

    Keep a min-heap containing only the k largest values seen so far. If a
    newly added value makes the heap larger than k, remove its smallest value.
    The heap top is then the k-th largest value, including after each add().

    Building from n initial values: O(n log k) time.
    Each add(): O(log k) time. Extra space: O(k).
*/
class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int rank, vector<int>& nums) : k(rank) {
        for (int value : nums) {
            minHeap.push(value);
            if (static_cast<int>(minHeap.size()) > k) {
                minHeap.pop();
            }
        }
    }

    int add(int value) {
        minHeap.push(value);
        if (static_cast<int>(minHeap.size()) > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

int main() {
    vector<int> initialValues = {4, 5, 8, 2};
    KthLargest kthLargest(3, initialValues);

    for (int value : vector<int>{3, 5, 10, 9, 4}) {
        cout << "After adding " << value << ": "
             << kthLargest.add(value) << endl;
    }
    return 0;
}
