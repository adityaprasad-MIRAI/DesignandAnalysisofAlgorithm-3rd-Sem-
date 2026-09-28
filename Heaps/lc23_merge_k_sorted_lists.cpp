#include "../include/standard.h"
using namespace std;

/*
    LeetCode 23: Merge k Sorted Lists

    Approach: put the first node from each non-empty list into a min-heap.
    Repeatedly remove the globally smallest node, append it to the merged list,
    and add that node's successor to the heap. Since each list is sorted, the
    successor is the next possible candidate from that list.

    Time: O(N log k)     Space: O(k)
    N is the total number of nodes and k is the number of lists.
*/
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int value) : val(value), next(nullptr) {}
    ListNode(int value, ListNode* nextNode) : val(value), next(nextNode) {}
};

class Solution {
private:
    struct CompareNodes {
        bool operator()(const ListNode* first, const ListNode* second) const {
            return first->val > second->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNodes> minHeap;

        for (ListNode* head : lists) {
            if (head != nullptr) {
                minHeap.push(head);
            }
        }

        ListNode dummy;
        ListNode* tail = &dummy;

        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }

            tail->next = smallest;
            tail = smallest;
        }
        tail->next = nullptr;
        return dummy.next;
    }
};

// Helpers below are only for constructing and displaying this standalone example.
ListNode* makeList(const vector<int>& values) {
    ListNode dummy;
    ListNode* tail = &dummy;

    for (int value : values) {
        tail->next = new ListNode(value);
        tail = tail->next;
    }
    return dummy.next;
}

void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* nextNode = head->next;
        delete head;
        head = nextNode;
    }
}

int main() {
    vector<ListNode*> lists = {
        makeList({1, 4, 5}),
        makeList({1, 3, 4}),
        makeList({2, 6})
    };

    Solution solution;
    ListNode* merged = solution.mergeKLists(lists);

    cout << "Merged list: ";
    for (ListNode* node = merged; node != nullptr; node = node->next) {
        cout << node->val << ' ';
    }
    cout << endl;

    deleteList(merged);
    return 0;
}
