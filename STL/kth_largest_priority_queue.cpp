#include "../include/standard.h"
using namespace std;

/*
    Problem: Find the k-th largest element using priority_queue
    ----------------------------------------------------------
    A priority_queue in C++ is a max-heap by default.
    To get the k-th largest element efficiently, we can create a min-heap of size k.

    Idea:
    - Keep only the k largest elements seen so far in a min-heap.
    - If a new number is smaller than the current heap top, ignore it.
    - If a new number is larger, push it and remove the smallest among the top k.
    - At the end, the heap top is the k-th largest element.

    Example:
    Input: nums = [3, 2, 1, 5, 6, 4], k = 2
    Output: 5
    Explanation: sorted array = [1, 2, 3, 4, 5, 6]; 2nd largest = 5
*/

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    // min-heap: stores only the k largest elements seen so far.
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int x : nums) {
        minHeap.push(x);

        // If heap size exceeds k, remove the smallest element.
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    cout << "Array: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    cout << "k = " << k << endl;
    cout << "The " << k << "-th largest element is: " << minHeap.top() << endl;

    return 0;
}
