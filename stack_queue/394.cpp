#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  string decodeString(string s) {
    if (s.empty()) return "";
    string result;
    int n = s.length();
    int i = 0;
    int c = 0;
    while (isdigit(s[i]) && i < n) {
      c = c * 10 + (s[i++] - '0');
    }
    int j = i;
    if (i < n && s[i] == '[') {
      int open = 1;
      while (++j < n && open) {
        if (s[j] == '[') ++open;
        if (s[j] == ']') --open;
      }
    } else {
      while (j < n && isalpha(s[j])) ++j;
    }
    if (i == 0) {
      return s.substr(i, j) + decodeString(s.substr(j));
    }
    string ss = decodeString(s.substr(i + 1, j - i - 2));
    while (c--) {
      result += ss;
    }
    result += decodeString(s.substr(j));
    return result;
  }
};