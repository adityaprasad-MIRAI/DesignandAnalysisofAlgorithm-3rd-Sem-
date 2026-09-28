#include "standard.h"
#include<queue>
using namespace std;

int main(){

    // Initialize a max-heap from a vector
    vector<int> values = {10, 30, 20};
    priority_queue<int> pq(values.begin(), values.end());

    cout << "Top element: " << pq.top() << endl;
    cout << "Size: " << pq.size() << endl;
    cout << "Is empty: " << boolalpha << pq.empty() << endl;

    // Add an element
    pq.push(40);
    cout << "Top after push: " << pq.top() << endl;

    // Remove the top element
    pq.pop();
    cout << "Top after pop: " << pq.top() << endl;
    cout << "Size after pop: " << pq.size() << endl;

    // Remove all remaining elements
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << endl;
    cout << "Is empty after removing all elements: " << pq.empty() << endl;

    // Creating a min-heap
    priority_queue<int,vector<int>,greater<int>>pq1;
    return 0;
}