#include "../include/standard.h"
using namespace std;

/*
    LeetCode 1046: Last Stone Weight

    Approach: a max-heap lets us repeatedly remove the two heaviest stones.
    If their weights differ, the remaining stone has weight y - x and is put
    back into the heap. Equal weights destroy both stones. The final heap top
    is the remaining weight; an empty heap means the answer is zero.

    Example: stones = [2, 7, 4, 1, 8, 1] -> 1

    Time: O(n log n)     Space: O(n)
*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end());

        while (maxHeap.size() > 1) {
            int heaviest = maxHeap.top();
            maxHeap.pop();
            int secondHeaviest = maxHeap.top();
            maxHeap.pop();

            if (heaviest != secondHeaviest) {
                maxHeap.push(heaviest - secondHeaviest);
            }
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};

int main() {
    vector<int> stones = {2, 7, 4, 1, 8, 1};

    Solution solution;
    cout << "Last stone weight: "
         << solution.lastStoneWeight(stones) << endl;
    return 0;
}
