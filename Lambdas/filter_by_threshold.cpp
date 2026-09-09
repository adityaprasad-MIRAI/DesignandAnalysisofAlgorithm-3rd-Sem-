#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    const std::vector<int> numbers{3, 12, 7, 25, 18, 4, 30};
    int threshold = 10;

    // This lambda captures threshold by value using [threshold].
    // It receives one number and returns true when that number should be
    // included in the filtered result.
    //
    // Capturing by value gives the lambda its own copy of threshold. That
    // copy remains available whenever the lambda is called by the algorithm.
    const auto is_at_least_threshold = [threshold](int number) {
        return number >= threshold;
    };

    std::vector<int> filtered_numbers;

    // copy_if copies only the elements for which the predicate returns true.
    std::copy_if(numbers.begin(), numbers.end(),
                 std::back_inserter(filtered_numbers),
                 is_at_least_threshold);

    std::cout << "Numbers at least " << threshold << ": ";
    for (int number : filtered_numbers) {
        std::cout << number << ' ';
    }
    std::cout << '\n';

    return 0;
}
