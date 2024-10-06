#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    // Create a min-heap (priority queue)
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int num : nums) {
        minHeap.push(num);
        
        // Maintain size of heap to k
        if (minHeap.size() > k) {
            minHeap.pop(); // Pop smallest element
        }
    }
    
    // The root of the min heap is the Kth largest element
    return minHeap.top();
}

int main() {
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;
    cout << "Kth largest element is " << findKthLargest(nums, k) << endl;
    return 0;
}
