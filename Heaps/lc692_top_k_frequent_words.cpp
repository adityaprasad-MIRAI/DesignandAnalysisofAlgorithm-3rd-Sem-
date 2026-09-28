#include "../include/standard.h"
using namespace std;

/*
    LeetCode 692: Top K Frequent Words

    Count each word, then retain k entries in a min-heap. The heap comparator
    makes the least desirable retained entry rise to the top: lower frequency
    first, and for equal frequencies, lexicographically larger words first.
    Removing that entry whenever size exceeds k leaves the requested words.
    Reverse the heap's removal order to produce frequency-descending,
    lexicographically-ascending output.

    Time: O(n + m log k + k)     Space: O(m + k)
    n is the input count and m is the number of distinct words.
*/
class Solution {
private:
    using WordFrequency = pair<string, int>;

    struct CompareWords {
        bool operator()(const WordFrequency& first,
                        const WordFrequency& second) const {
            if (first.second != second.second) {
                return first.second > second.second;
            }
            return first.first < second.first;
        }
    };

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> frequency;
        for (const string& word : words) {
            ++frequency[word];
        }

        if (k <= 0 || k > static_cast<int>(frequency.size())) {
            return {};
        }

        priority_queue<WordFrequency, vector<WordFrequency>, CompareWords> minHeap;
        for (const auto& entry : frequency) {
            minHeap.push({entry.first, entry.second});
            if (static_cast<int>(minHeap.size()) > k) {
                minHeap.pop();
            }
        }

        vector<string> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().first);
            minHeap.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;

    Solution solution;
    vector<string> result = solution.topKFrequent(words, k);

    cout << "Top " << k << " words: ";
    for (const string& word : result) {
        cout << word << ' ';
    }
    cout << endl;
    return 0;
}
