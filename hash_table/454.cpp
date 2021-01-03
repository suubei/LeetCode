#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C,
                   vector<int>& D) {
    unordered_map<int, int> sums;
    for (const int a : A) {
      for (const int b : B) {
        ++sums[a + b];
      }
    }
    int result = 0;
    for (const int c : C) {
      for (const int d : D) {
        auto it = sums.find(-c - d);
        if (it != sums.end()) {
          result += it->second;
        }
      }
    }
    return result;
  }
};