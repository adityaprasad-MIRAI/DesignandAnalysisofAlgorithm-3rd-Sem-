#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8};

    // remove_if moves the elements that should be kept toward the beginning
    // of the vector. It returns an iterator to the new logical end, but it
    // does not change the vector's physical size by itself.
    const auto new_end = std::remove_if(numbers.begin(), numbers.end(),
                                        [](int number) {
                                            // true means "remove this item".
                                            return number % 2 != 0;
                                        });

    // erase completes the erase-remove idiom by deleting the unused tail.
    numbers.erase(new_end, numbers.end());

    std::cout << "After removing odd numbers: ";
    for (int number : numbers) {
        std::cout << number << ' ';
    }
    std::cout << '\n';

    return 0;
}
