#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
 public:
  MyQueue() {}

  void push(int x) { s1_.push(x); }

  int pop() {
    if (s2_.empty()) move();
    int top = s2_.top();
    s2_.pop();
    return top;
  }

  int peek() {
    if (s2_.empty()) move();
    return s2_.top();
  }

  bool empty() { return s1_.empty() && s2_.empty(); }

 private:
  stack<int> s1_;
  stack<int> s2_;

  void move() {
    while (!s1_.empty()) {
      s2_.push(s1_.top());
      s1_.pop();
    }
  }
};