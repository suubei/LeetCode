#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    for (const int n : nums) {
      ++count[n];
    }
    priority_queue<pair<int, int>> q;
    for (const auto& p : count) {
      q.emplace(-p.second, p.first);
      if (q.size() > k) q.pop();
    }
    vector<int> result;
    while (!q.empty()) {
      result.push_back(q.top().second);
      q.pop();
    }
    return result;
  }
};