#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int S) {
    const int n = nums.size();
    const int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < S) return 0;
    const int offset = sum;
    vector<vector<int>> ways(n + 1, vector<int>(sum + offset + 1, 0));
    ways[0][offset] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = nums[i]; j < 2 * sum + 1 - nums[i]; ++j) {
        if (ways[i][j]) {
          ways[i + 1][j + nums[i]] += ways[i][j];
          ways[i + 1][j - nums[i]] += ways[i][j];
        }
      }
    }
    return ways.back()[offset + S];
  }
};