#include <string.h>

#include <iostream>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int array[128];
    memset(array, -1, sizeof(array));
    int result = 0;
    int len = s.length();
    for (int i = 0, j = 0; j < len; j++) {
      i = max(i, array[s[j]] + 1);
      result = max(result, j - i + 1);
      array[s[j]] = j;
    }
    return result;
  }
};