// Kth Largest Element in a Stream
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class KthLargest {
 private:
  priority_queue<int, vector<int>, greater<int>> heap;
  int size;

 public:
  KthLargest(int k, vector<int>& nums) {
    size = k;
    for (int x : nums) {
      add(x);
    }
  }

  int add(int val) {
    if (heap.size() < size) {
      heap.push(val);
    } else if (heap.top() < val) {
      heap.push(val);
      heap.pop();
    }
    return heap.top();
  }
};