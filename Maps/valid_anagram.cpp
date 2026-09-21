#include "standard.h"
using namespace std;

/*
    Problem: Valid Anagram
    ---------------------
    Two strings are anagrams if they contain the same characters with the same counts.

    Idea:
    - If lengths differ, they cannot be anagrams.
    - Count character differences between the two strings.
    - If every character difference is zero, they are anagrams.

    Example:
    Input: "listen", "silent"
    Output: VALID ANAGRAMS
*/

int main() {
    string s1 = "listen";
    string s2 = "silent";

    unordered_map<char, int> freq;

    if (s1.size() != s2.size()) {
        cout << "INVALID ANAGRAMS" << endl;
        return 0;
    }

    // Add counts from s1 and subtract counts from s2.
    for (int i = 0; i < s1.size(); i++) {
        freq[s1[i]]++;
        freq[s2[i]]--;
    }

    bool isAnagram = true;
    for (const auto &entry : freq) {
        if (entry.second != 0) {
            isAnagram = false;
            break;
        }
    }

    cout << "String 1: " << s1 << endl;
    cout << "String 2: " << s2 << endl;
    cout << (isAnagram ? "VALID ANAGRAMS" : "INVALID ANAGRAMS") << endl;

    return 0;
}