#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    const std::vector<int> numbers{4, 9, 12, 7, 20, 3};
    const int k = 10;

    // find_if examines elements from left to right and stops at the first
    // element for which the predicate returns true.
    // The lambda captures k by value and checks whether a number is greater.
    const auto position = std::find_if(
        numbers.begin(), numbers.end(), [k](int number) {
            return number > k;
        });

    std::cout << "First element greater than " << k << ": ";
    if (position != numbers.end()) {
        // Dereference the iterator to obtain the matching element.
        std::cout << *position << '\n';
    } else {
        // end() means that no element satisfied the condition.
        std::cout << "none\n";
    }

    return 0;
}
