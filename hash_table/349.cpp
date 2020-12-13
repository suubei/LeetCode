#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> s(nums1.begin(), nums1.end());
    vector<int> result;
    for (int i : nums2) {
      if (s.count(i) > 0) {
        result.push_back(i);
        s.erase(i);
      }
    }
    return result;
  }
};