#include <iostream>
#include <vector>
#include <queue>
#include<iostream>
class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    // Constructor
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            add(num);
        }
    }
    // Add new value and return kth largest
    int add(int val) {
        minHeap.push(val);
        // Keep only k largest elements
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top(); // kth largest element
    }
};
// Example usage
int main() {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest obj(3, nums);
    cout << obj.add(3) << endl;   // Output: 4
    cout << obj.add(5) << endl;   // Output: 5
    cout << obj.add(10) << endl;  // Output: 5
    cout << obj.add(9) << endl;   // Output: 8
    cout << obj.add(4) << endl;   // Output: 8
    return 0;
}