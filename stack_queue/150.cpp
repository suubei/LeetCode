#include <cctype>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> s;
    for (const string& token : tokens) {
      if (isdigit(token.back())) {
        s.push(stoi(token));
      } else {
        int n = 0;
        int n2 = s.top();
        s.pop();
        int n1 = s.top();
        s.pop();
        switch (token.back()) {
          case '+':
            n = n1 + n2;
            break;
          case '-':
            n = n1 - n2;
            break;
          case '*':
            n = n1 * n2;
            break;
          default:
            n = n1 / n2;
            break;
        }
        s.push(n);
      }
    }
    return s.top();
  }
};