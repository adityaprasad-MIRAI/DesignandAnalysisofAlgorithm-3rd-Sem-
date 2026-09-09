#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> words{
        "pear", "apple", "fig", "banana", "kiwi", "plum"};

    // The lambda sorts by two criteria:
    // 1. Shorter strings come first.
    // 2. Strings with equal length are ordered lexicographically, which is
    //    dictionary order based on the characters in each string.
    std::sort(words.begin(), words.end(), [](const std::string& left,
                                             const std::string& right) {
        if (left.length() != right.length()) {
            return left.length() < right.length();
        }
        return left < right;
    });

    std::cout << "Strings sorted by length, then lexicographically:\n";
    for (const std::string& word : words) {
        std::cout << word << '\n';
    }

    return 0;
}
