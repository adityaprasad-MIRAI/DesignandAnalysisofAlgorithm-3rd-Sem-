#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    std::vector<std::pair<int, int>> pairs{
        {3, 2}, {1, 4}, {2, 2}, {5, 1}, {4, 4}};

    // The lambda defines the complete sorting rule:
    // 1. Compare the second values first, in ascending order.
    // 2. If those values are equal, compare the first values.
    //
    // The second condition is a tie-breaker. It makes the result
    // deterministic when two pairs have the same second value.
    std::sort(pairs.begin(), pairs.end(), [](const auto& left, const auto& right) {
        if (left.second != right.second) {
            return left.second < right.second;
        }
        return left.first < right.first;
    });

    std::cout << "Pairs sorted by second value, then first value:\n";
    for (const auto& [first, second] : pairs) {
        std::cout << "(" << first << ", " << second << ") ";
    }
    std::cout << '\n';

    return 0;
}
