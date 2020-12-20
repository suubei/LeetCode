#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<int>> m;
    for (int i = 0; i < strs.size(); i++) {
      string str = strs[i];
      sort(str.begin(), str.end());
      m[str].push_back(i);
    }
    vector<vector<string>> result;
    for (const auto& kv : m) {
      result.push_back({});
      for (int i : kv.second) {
        result.back().push_back(strs[i]);
      }
    }
    return result;
  }
};