#include <iostream>
#include <queue>

using namespace std;

class MyStack {
 public:
  MyStack() {}

  void push(int x) {
    q_.push(x);
    for (int i = 1; i < q_.size(); ++i) {
      q_.push(q_.front());
      q_.pop();
    }
  }

  int pop() {
    int top = q_.front();
    q_.pop();
    return top;
  }

  int top() { return q_.front(); }

  bool empty() { return q_.empty(); }

 private:
  queue<int> q_;
};