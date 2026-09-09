// count_greater_than_k.cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> dataset = {4, 8, 15, 16, 23, 42};
    int threshold = 10;

    // std::count_if utilizing a lambda that captures the threshold by value.
    // The algorithm evaluates the lambda for each element, incrementing the count when true.
    int count = count_if(dataset.begin(), dataset.end(), [threshold](int element) {
        return element > threshold;
    });

    cout << "Number of elements strictly greater than " << threshold << ": " << count << "\n";

    return 0;
}