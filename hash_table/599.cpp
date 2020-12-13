// Minimum Index Sum of Two Lists
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> map;
    for (int i = 0; i < list1.size(); i++) {
      map[list1[i]] = i;
    }
    vector<string> result;
    int sum = 100000;
    for (int i = 0; i < list2.size(); i++) {
      if (map.count(list2[i])) {
        if (map[list2[i]] + i < sum) {
          sum = map[list2[i]] + i;
          result.clear();
          result.push_back(list2[i]);
        } else if (map[list2[i]] + i == sum) {
          result.push_back(list2[i]);
        }
      }
    }
    return result;
  }
};