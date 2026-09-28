#include "../include/standard.h"
using namespace std;

/*
    LeetCode 451: Sort Characters By Frequency

    Count character frequencies, then put (frequency, character) pairs into a
    max-heap. Repeatedly take the most frequent remaining character and append
    it the required number of times. Characters with equal frequencies may
    appear in either order, which is valid for this problem.

    Time: O(n + u log u)     Space: O(u + n)
    n is the string length and u is the number of distinct characters.
*/
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> frequency;
        for (char character : s) {
            ++frequency[character];
        }

        priority_queue<pair<int, char>> maxHeap;
        for (const auto& entry : frequency) {
            maxHeap.push({entry.second, entry.first});
        }

        string result;
        result.reserve(s.size());
        while (!maxHeap.empty()) {
            int count = maxHeap.top().first;
            char character = maxHeap.top().second;
            maxHeap.pop();
            result.append(count, character);
        }
        return result;
    }
};

int main() {
    string text = "tree";

    Solution solution;
    cout << "Characters sorted by frequency: "
         << solution.frequencySort(text) << endl;
    return 0;
}
