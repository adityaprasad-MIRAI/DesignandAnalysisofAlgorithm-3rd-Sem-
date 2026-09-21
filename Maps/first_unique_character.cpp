#include "standard.h"
using namespace std;

/*
    Problem: First Unique Character in a String
    ------------------------------------------
    Return the index of the first character that appears exactly once.
    If no such character exists, return -1.

    Example:
    Input: "leetcode"
    Output: 0
    because 'l' is the first character with frequency 1.
*/

int main() {
    string s = "leetcode";

    // Step 1: Count frequency of each character.
    unordered_map<char, int> freq;
    for (char ch : s) {
        freq[ch]++;
    }

    // Step 2: Find the first character whose count is exactly 1.
    int answer = -1;
    for (int i = 0; i < s.size(); i++) {
        if (freq[s[i]] == 1) {
            answer = i;
            break;
        }
    }

    cout << "String: " << s << endl;
    cout << "Index of first unique character: " << answer << endl;

    return 0;
}