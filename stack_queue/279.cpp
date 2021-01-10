#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int numSquares(int n) {
    vector<int> count(n + 1, -1);
    queue<int> q;
    count[0] = 0;
    q.push(0);
    while (!q.empty()) {
      int m = q.front();
      q.pop();
      for (int i = 1; i * i + m <= n; i++) {
        if (count[i * i + m] == -1) {
          count[i * i + m] = count[m] + 1;
          q.push(i * i + m);
        }
        if (i * i + m == n) {
          return count[n];
        }
      }
    }
    return count[n];
  }
};