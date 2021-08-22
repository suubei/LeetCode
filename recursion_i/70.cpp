// Climbing Stairs
#include <iostream>

using namespace std;

class Solution {
 public:
  int climbStairs(int n) {
    int one = 1;
    int two = 1;
    int curr = 1;
    for (int i = 2; i <= n; i++) {
      curr = one + two;
      one = two;
      two = curr;
    }
    return curr;
  }
};