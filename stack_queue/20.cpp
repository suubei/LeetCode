#include <iostream>
#include <stack>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    for (const char& c : s) {
      if (st.empty()) {
        st.push(c);
      } else if ((st.top() == '(' && c == ')') ||
                 (st.top() == '{' && c == '}') ||
                 (st.top() == '[' && c == ']')) {
        st.pop();
      } else {
        st.push(c);
      }
    }

    return st.empty();
  }

 private:
  stack<int> st;
};