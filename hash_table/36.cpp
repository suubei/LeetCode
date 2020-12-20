#include <string.h>

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>> &board) {
    int flags[9];
    for (int i = 0; i < 9; i++) {
      memset(flags, 0, sizeof(int) * 9);
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          int key = board[i][j] - '1';
          if (flags[key] == 0) {
            flags[key] = 1;
          } else {
            return false;
          }
        }
      }
    }

    for (int i = 0; i < 9; i++) {
      memset(flags, 0, sizeof(int) * 9);
      for (int j = 0; j < 9; j++) {
        if (board[j][i] != '.') {
          int key = board[j][i] - '1';
          if (flags[key] == 0) {
            flags[key] = 1;
          } else {
            return false;
          }
        }
      }
    }

    for (int row = 0, col = 0; row < 9;) {
      memset(flags, 0, sizeof(int) * 9);
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if (board[row + i][col + j] != '.') {
            int key = board[row + i][col + j] - '1';
            if (flags[key] == 0) {
              flags[key] = 1;
            } else {
              return false;
            }
          }
        }
      }

      if (col == 6) {
        col = 0;
        row += 3;
      } else {
        col += 3;
      }
    }
    return true;
  }
};