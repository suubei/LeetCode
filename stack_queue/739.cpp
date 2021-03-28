#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& T) {
    const int n = T.size();
    vector<int> result = vector<int>(n);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
      while (!s.empty() && T[s.top()] <= T[i]) {
        s.pop();
      }
      result[i] = s.empty() ? 0 : s.top() - i;
      s.push(i);
    }
    return result;
  }
};