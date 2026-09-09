#include <iostream>

// This function creates and returns a lambda.
//
// The return type is written as auto because every lambda has a unique,
// compiler-generated type that cannot be named directly in C++ source code.
// The returned lambda captures factor by value, so it owns a copy that stays
// alive after make_multiplier has finished executing.
auto make_multiplier(int factor) {
    return [factor](int value) {
        return value * factor;
    };
}

int main() {
    // Calling the function produces a lambda that remembers the factor 3.
    const auto multiply_by_three = make_multiplier(3);

    // The returned lambda can be called like an ordinary function.
    std::cout << "3 multiplied by 10 = " << multiply_by_three(10) << '\n';
    std::cout << "3 multiplied by 7 = " << multiply_by_three(7) << '\n';

    // A second call creates a separate lambda with its own captured factor.
    const auto multiply_by_five = make_multiplier(5);
    std::cout << "5 multiplied by 6 = " << multiply_by_five(6) << '\n';

    return 0;
}
