#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> wordFrequency;
    string word;

    cout << "Enter words separated by spaces (press Ctrl+Z then Enter to finish):\n";

    // Reading with >> treats spaces, tabs, and newlines as separators.
    while (cin >> word) {
        ++wordFrequency[word];
    }

    cout << "\nWord frequencies:\n";
    for (const auto& entry : wordFrequency) {
        cout << entry.first << ": " << entry.second << '\n';
    }

    return 0;
}
