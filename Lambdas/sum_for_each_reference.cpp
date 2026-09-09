#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    // A vector whose elements we want to add together.
    const std::vector<int> numbers{10, 20, 30, 40, 50};

    // The accumulator stores the running total.
    int sum = 0;

    // for_each calls the lambda once for every element in numbers.
    //
    // [ &sum ] is the capture list. It captures sum by reference, so
    // changes made to sum inside the lambda update the original variable.
    // If sum were captured by value as [sum], each call would work with a
    // copy and the original accumulator would remain 0.
    std::for_each(numbers.begin(), numbers.end(), [&sum](int number) {
        sum += number;
    });

    std::cout << "Sum = " << sum << '\n';
    return 0;
}
