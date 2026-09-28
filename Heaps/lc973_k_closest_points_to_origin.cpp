#include "../include/standard.h"
using namespace std;

/*
    LeetCode 973: K Closest Points to Origin

    The squared distance of (x, y) from the origin is x*x + y*y; there is no
    need to calculate a square root because square root preserves ordering.
    Keep a max-heap of at most k points. Its top is the farthest point among
    the retained candidates, so discard it whenever a closer point arrives.

    Time: O(n log k)     Space: O(k)
    The returned points may be in any order, as allowed by the problem.
*/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using PointEntry = pair<long long, pair<int, int>>;
        priority_queue<PointEntry> maxHeap;

        for (const vector<int>& point : points) {
            long long x = point[0];
            long long y = point[1];
            long long squaredDistance = x * x + y * y;

            maxHeap.push({squaredDistance, {point[0], point[1]}});
            if (static_cast<int>(maxHeap.size()) > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            const auto& coordinates = maxHeap.top().second;
            result.push_back({coordinates.first, coordinates.second});
            maxHeap.pop();
        }
        return result;
    }
};

int main() {
    vector<vector<int>> points = {{1, 3}, {-2, 2}};
    int k = 1;

    Solution solution;
    vector<vector<int>> result = solution.kClosest(points, k);

    cout << k << " closest point(s): ";
    for (const vector<int>& point : result) {
        cout << "(" << point[0] << ", " << point[1] << ") ";
    }
    cout << endl;
    return 0;
}
