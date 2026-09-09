#include <functional>
#include <iostream>
#include <vector>

int main() {
    // Every lambda below takes one int and returns one int.
    // Therefore, all three can be stored in this common function type:
    // std::function<int(int)>
    using IntegerFunction = std::function<int(int)>;

    // The vector stores three different operations as callable objects.
    // A lambda can be assigned to std::function when its parameter and
    // return types match the std::function signature.
    const std::vector<IntegerFunction> operations{
        [](int value) {
            return value + 10;
        },
        [](int value) {
            return value * 2;
        },
        [](int value) {
            return value * value;
        }};

    const int input = 5;
    std::cout << "Input = " << input << '\n';

    // Each element of operations is called just like an ordinary function.
    // The operations are applied independently to the same input value.
    for (std::size_t index = 0; index < operations.size(); ++index) {
        std::cout << "Operation " << index + 1 << " result = "
                  << operations[index](input) << '\n';
    }

    return 0;
}
