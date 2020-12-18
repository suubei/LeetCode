#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int size = min<int>(nums.size(), k + 1);
    set<int> s;
    for (int i = 0; i < size; i++) {
      if (s.find(nums[i]) != s.end()) {
        return true;
      }
      s.insert(nums[i]);
    }
    for (int i = k + 1; i < nums.size(); i++) {
      s.erase(nums[i - k - 1]);
      if (s.find(nums[i]) != s.end()) {
        return true;
      }
      s.insert(nums[i]);
    }
    return false;
  }
};