#include <iostream>
#include <stack>

using namespace std;

class MinStack {
 public:
  MinStack() {}

  void push(int x) {
    s.push(x);
    if (min.empty() || x <= min.top()) {
      min.push(x);
    }
  }

  void pop() {
    int top = s.top();
    s.pop();
    if (top == min.top()) {
      min.pop();
    }
  }

  int top() { return s.top(); }

  int getMin() { return min.top(); }

 private:
  stack<int> min;
  stack<int> s;
};
