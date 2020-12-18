// First Unique Character in a String
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int firstUniqChar(string s) {
    int chars[256] = {};
    for (int i = 0; i < s.size(); i++) {
      int c = s[i];
      if (chars[c] == 0) {
        chars[c] = i + 1;
      } else {
        chars[c] = -1;
      }
    }
    int result = -1;
    for (int i : chars) {
      if (i > 0 && (result == -1 || i - 1 < result)) {
        result = i - 1;
      }
    }
    return result;
  }
};