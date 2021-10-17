// Sort an Array
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    mergeSort(nums, 0, nums.size());
    return nums;
  }

 private:
  void mergeSort(vector<int>& nums, int l, int r) {
    if (l + 1 == r) return;
    vector<int> t(r - l);
    int m = l + (r - l) / 2;
    mergeSort(nums, l, m);
    mergeSort(nums, m, r);
    int i = l;
    int j = m;
    int index = 0;
    while (i < m || j < r) {
      if (j == r || (i < m && nums[i] < nums[j])) {
        t[index++] = nums[i++];
      } else {
        t[index++] = nums[j++];
      }
    }
    copy(t.begin(), t.end(), nums.begin() + l);
  }
};