#include "../include/standard.h"
using namespace std;

/*
    LeetCode 3: Longest Substring Without Repeating Characters

    Maintain a sliding window [windowStart, currentIndex] with no repeated
    characters. lastSeen stores the most recent index of each character. On a
    repeat inside the current window, move windowStart just past that previous
    occurrence; never move the start backward. Update the best window length
    after processing each character.

    Time: O(n) average     Space: O(min(n, character set size))
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int windowStart = 0;
        int longestLength = 0;

        for (int currentIndex = 0;
             currentIndex < static_cast<int>(s.size()); ++currentIndex) {
            char character = s[currentIndex];
            auto previous = lastSeen.find(character);
            if (previous != lastSeen.end() && previous->second >= windowStart) {
                windowStart = previous->second + 1;
            }

            lastSeen[character] = currentIndex;
            longestLength = max(longestLength, currentIndex - windowStart + 1);
        }
        return longestLength;
    }
};

int main() {
    string text = "abcabcbb";

    Solution solution;
    cout << "Longest substring length: "
         << solution.lengthOfLongestSubstring(text) << endl;
    return 0;
}
