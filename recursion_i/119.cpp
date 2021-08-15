// Pascal's Triangle II

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> result(rowIndex + 1, 1);
    getRowRecursive(rowIndex, result);
    return result;
  }

 private:
  void getRowRecursive(int rowIndex, vector<int>& vec) {
    if (rowIndex == 0) {
      vec[rowIndex] = 1;
    } else {
      getRowRecursive(rowIndex - 1, vec);
      vector<int> tmp(vec);
      for (int i = 0; i <= rowIndex; i++) {
        if (i == 0 || i == rowIndex) {
          vec[i] = 1;
        } else {
          vec[i] = tmp[i - 1] + tmp[i];
        }
      }
    }
  }
};