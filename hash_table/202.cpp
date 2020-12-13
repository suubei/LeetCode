// Happy Number
#include <vector>

using namespace std;

class Solution {
 public:
  bool isHappy(int n) {
    vector<bool> flags(810, false);
    while (true) {
      n = calculate(n);
      if (n == 1) return true;
      if (flags[n]) return false;
      flags[n] = true;
    }
    return true;
  }

 private:
  int calculate(int n) {
    int result = 0;
    while (n > 0) {
      int m = n % 10;
      n /= 10;
      result += m * m;
    }
    return result;
  }
};