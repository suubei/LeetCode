#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> result(m, vector<int>(n, INT_MAX - n * m));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j]) {
          if (i > 0) result[i][j] = min(result[i][j], result[i - 1][j] + 1);
          if (j > 0) result[i][j] = min(result[i][j], result[i][j - 1] + 1);
        } else {
          result[i][j] = 0;
        }
      }
    }
    for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        if (i < m - 1) result[i][j] = min(result[i][j], result[i + 1][j] + 1);
        if (j < n - 1) result[i][j] = min(result[i][j], result[i][j + 1] + 1);
      }
    }
    return result;
  }
};