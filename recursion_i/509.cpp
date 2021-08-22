// Fibonacci Number
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  int fib(int n) {
    if (cache[n]) {
      return cache[n];
    }
    if (n < 2) {
      return n;
    } else {
      int r = fib(n - 1) + fib(n - 2);
      cache[n] = r;
      return r;
    }
  }

 private:
  map<int, int> cache;
};