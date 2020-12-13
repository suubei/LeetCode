#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    multiset<long> s;
    for (int i = 0; i < nums.size(); i++) {
      if (i > k) {
        s.erase(s.find(nums[i - k - 1]));
      }
      auto it = s.insert(nums[i]);
      if (it != begin(s) && *it - *prev(it) <= t) {
        return true;
      }
      if (next(it) != end(s) && *next(it) - *it <= t) {
        return true;
      }
    }
    return false;
  }
};