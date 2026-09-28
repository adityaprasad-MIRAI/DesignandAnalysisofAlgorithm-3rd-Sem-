#include "../include/standard.h"
using namespace std;

/*
    LeetCode 49: Group Anagrams

    Anagrams contain the same letters, so sorting each word produces a shared
    canonical key. Use that key in a hash map and append words with the same
    key to the same group. The order of groups and words within a group is not
    significant for this problem.

    Time: O(n * L log L)     Space: O(n * L)
    n is the number of words and L is the maximum word length.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& word : strs) {
            string key = word;
            sort(key.begin(), key.end());
            groups[key].push_back(word);
        }

        vector<vector<string>> result;
        for (auto& entry : groups) {
            result.push_back(move(entry.second));
        }
        return result;
    }
};

int main() {
    vector<string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};

    Solution solution;
    vector<vector<string>> groups = solution.groupAnagrams(words);

    cout << "Anagram groups:" << endl;
    for (const vector<string>& group : groups) {
        cout << "[ ";
        for (const string& word : group) {
            cout << word << ' ';
        }
        cout << "]" << endl;
    }
    return 0;
}
