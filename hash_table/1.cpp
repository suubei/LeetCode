// Two Sum
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    for (int i = 0; i < nums.size() - 1; i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
          result.push_back(i);
          result.push_back(j);
          return result;
        }
      }
    }
    return result;
  }
};

// class Solution {
//  public:
//   vector<int> twoSum(vector<int>& nums, int target) {
//     unordered_map<int, int> map;
//     for (int i = 0; i < nums.size(); i++) {
//       map[nums[i]] = i;
//     }
//     vector<int> result;
//     for (int i = 0; i < nums.size(); i++) {
//       int a = nums[i];
//       int b = target - a;
//       if (map.count(b) && i != map[b]) {
//         result.push_back(i);
//         result.push_back(map[b]);
//         return result;
//       }
//     }
//     return result;
//   }
// };