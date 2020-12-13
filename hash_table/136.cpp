// Single Number
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      result ^= nums[i];
    }
    return result;
  }
};

// class Solution {
//  public:
//   int singleNumber(vector<int>& nums) {
//     unordered_set<int> set;
//     for (int i : nums) {
//       if (set.count(i) == 0) {
//         set.insert(i);
//       } else {
//         set.erase(i);
//       }
//     }
//     return *(set.begin());
//   }
// };