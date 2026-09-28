#include "../include/standard.h"
using namespace std;

/*
    LeetCode 295: Find Median from Data Stream

    Approach: divide the values into two heaps:
    - lowerHalf is a max-heap containing the smaller half.
    - upperHalf is a min-heap containing the larger half.

    Keep lowerHalf the same size as upperHalf or one element larger. This
    maintains the ordering lowerHalf.top() <= upperHalf.top(). If the counts
    are equal, the median is the average of the two tops; otherwise the top of
    lowerHalf is the median. Each insertion takes O(log n), while reading the
    median takes O(1). The two heaps use O(n) space.
*/
class MedianFinder {
private:
    priority_queue<int> lowerHalf;
    priority_queue<int, vector<int>, greater<int>> upperHalf;

public:
    void addNum(int num) {
        if (lowerHalf.empty() || num <= lowerHalf.top()) {
            lowerHalf.push(num);
        } else {
            upperHalf.push(num);
        }

        // Restore the size rule: lowerHalf has either equal size or one extra.
        if (lowerHalf.size() > upperHalf.size() + 1) {
            upperHalf.push(lowerHalf.top());
            lowerHalf.pop();
        } else if (upperHalf.size() > lowerHalf.size()) {
            lowerHalf.push(upperHalf.top());
            upperHalf.pop();
        }
    }

    double findMedian() const {
        if (lowerHalf.empty()) {
            return 0.0;
        }

        if (lowerHalf.size() == upperHalf.size()) {
            return (static_cast<double>(lowerHalf.top()) + upperHalf.top()) / 2.0;
        }
        return lowerHalf.top();
    }
};

int main() {
    MedianFinder medianFinder;
    vector<int> stream = {1, 2, 3, 4};

    for (int value : stream) {
        medianFinder.addNum(value);
        cout << "After adding " << value
             << ", median = " << medianFinder.findMedian() << endl;
    }
    return 0;
}
