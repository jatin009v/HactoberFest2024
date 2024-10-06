#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Custom comparator for the min-heap
struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    // Min-heap (priority queue)
    priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

    // Push the head of each list into the heap
    for (auto list : lists) {
        if (list) minHeap.push(list);
    }

    // Create a dummy node to help with result list creation
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    // Extract the minimum element from the heap, add it to the result list
    while (!minHeap.empty()) {
        ListNode* smallest = minHeap.top();
        minHeap.pop();
        current->next = smallest;
        current = current->next;

        // If there's a next node in the list, push it into the heap
        if (smallest->next) {
            minHeap.push(smallest->next);
        }
    }

    return dummy->next;
}

int main() {
    // Example usage
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);

    vector<ListNode*> lists = {list1, list2, list3};
    ListNode* result = mergeKLists(lists);

    // Output the merged list
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
