// Isomorphic Strings
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    vector<int> s_value(256, -1);
    vector<bool> t_value(256, false);
    for (int i = 0; i < s.size(); i++) {
      int a = s[i];
      int b = t[i];
      if (s_value[a] == -1) {
        if (t_value[b]) {
          return false;
        }
        s_value[a] = b;
        t_value[b] = true;
      } else if (s_value[a] != b) {
        return false;
      }
    }
    return true;
  }
};

// class Solution {
//  public:
//   bool isIsomorphic(string s, string t) {
//     unordered_map<char, char> map;
//     unordered_map<char, bool> flag;
//     for (int i = 0; i < s.length(); i++) {
//       if (!map.count(s[i])) {
//         if (flag[t[i]]) {
//           return false;
//         }
//         map[s[i]] = t[i];
//         flag[t[i]] = true;
//       } else if (map[s[i]] != t[i]) {
//         return false;
//       }
//     }
//     return true;
//   }
// };