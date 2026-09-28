#include "../include/standard.h"
using namespace std;

/*
    LeetCode 378: Kth Smallest Element in a Sorted Matrix

    Treat each matrix row as a sorted list. Insert the first value of every
    row into a min-heap. Each pop yields the next smallest unprocessed value;
    then insert the next value from that same row. After k pops, the last value
    removed is the answer. The heap stores no more than one candidate per row.

    For an n-row matrix: O(n + k log n) time and O(n) extra space.
*/
class Solution {
private:
    struct Entry {
        int value;
        int row;
        int column;
    };

    struct CompareEntries {
        bool operator()(const Entry& first, const Entry& second) const {
            return first.value > second.value;
        }
    };

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<Entry, vector<Entry>, CompareEntries> minHeap;

        for (int row = 0; row < static_cast<int>(matrix.size()); ++row) {
            if (!matrix[row].empty()) {
                minHeap.push({matrix[row][0], row, 0});
            }
        }

        int value = 0;
        while (k > 0 && !minHeap.empty()) {
            Entry smallest = minHeap.top();
            minHeap.pop();
            value = smallest.value;
            --k;

            int nextColumn = smallest.column + 1;
            if (nextColumn < static_cast<int>(matrix[smallest.row].size())) {
                minHeap.push({matrix[smallest.row][nextColumn],
                              smallest.row, nextColumn});
            }
        }
        return value;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;

    Solution solution;
    cout << "The " << k << "-th smallest value is "
         << solution.kthSmallest(matrix, k) << endl;
    return 0;
}
