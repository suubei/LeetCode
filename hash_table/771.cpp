#include <iostream>

using namespace std;

class Solution {
 public:
  int numJewelsInStones(string jewels, string stones) {
    int array[58];
    for (const char c : stones) {
      array[c - 'A'] += 1;
    }
    int total = 0;
    for (const char c : jewels) {
      total += array[c - 'A'];
    }
    return total;
  }
};