#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int openLock(vector<string>& deadends, string target) {
    const string start = "0000";
    unordered_set<string> s(deadends.begin(), deadends.end());
    if (s.count(target) || s.count(start)) return -1;
    if (start == target) return 0;
    unordered_set<string> v1{start};
    unordered_set<string> v2{target};
    queue<string> q1;
    q1.push(start);
    queue<string> q2;
    q2.push(target);
    int c1 = 0;
    int c2 = 0;
    while (!q1.empty() && !q2.empty()) {
      ++c1;
      const int size = q1.size();
      for (int t = 0; t < size; t++) {
        const string cur = q1.front();
        q1.pop();
        for (int i = 0; i < 4; i++) {
          for (int j = -1; j <= 1; j += 2) {
            string next = cur;
            next[i] = (next[i] - '0' + j + 10) % 10 + '0';
            if (v2.count(next)) return c1 + c2;
            if (!s.count(next) && !v1.count(next)) {
              v1.insert(next);
              q1.push(next);
            }
          }
        }
      }
      swap(q1, q2);
      swap(v1, v2);
      swap(c1, c2);
    }
    return -1;
  }
};