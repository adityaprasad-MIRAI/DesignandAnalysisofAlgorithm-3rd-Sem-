// generic_lambda_add.cpp
#include <iostream>

using namespace std;

int main() {
    // Generic lambda utilizing 'auto' parameters.
    // This C++14 feature allows the compiler to deduce the type at the point of invocation.
    auto add = [](auto a, auto b) {
        return a + b;
    };

    // Verifying type deduction with integer arguments
    int intResult = add(10, 25);
    
    // Verifying type deduction with double arguments
    double doubleResult = add(3.14, 2.71);

    cout << "Integer addition result: " << intResult << "\n";
    cout << "Double addition result: " << doubleResult << "\n";

    return 0;
}