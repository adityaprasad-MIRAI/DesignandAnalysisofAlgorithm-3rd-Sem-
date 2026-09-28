#include "../include/standard.h"
using namespace std;

/*
    GeeksforGeeks: Minimum Cost of Ropes

    Joining two ropes costs the sum of their lengths. To minimize the total,
    repeatedly join the two shortest ropes: every joined length contributes
    to later joins, so keeping intermediate lengths small minimizes the sum.
    A min-heap makes both shortest ropes available at its top.

    Example: lengths = [4, 3, 2, 6] -> 29
    Joins: 2+3=5, 4+5=9, 6+9=15; total cost = 5+9+15.

    Time: O(n log n)     Space: O(n)
*/
class Solution {
public:
    long long minCost(vector<long long>& ropes) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap(
            ropes.begin(), ropes.end());
        long long totalCost = 0;

        while (minHeap.size() > 1) {
            long long first = minHeap.top();
            minHeap.pop();
            long long second = minHeap.top();
            minHeap.pop();

            long long joinedLength = first + second;
            totalCost += joinedLength;
            minHeap.push(joinedLength);
        }

        return totalCost;
    }
};

int main() {
    vector<long long> ropes = {4, 3, 2, 6};

    Solution solution;
    cout << "Minimum total joining cost: " << solution.minCost(ropes) << endl;
    return 0;
}
