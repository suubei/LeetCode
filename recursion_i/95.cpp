// Unique Binary Search Trees II
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<TreeNode *> generateTrees(int n) { return generateTrees(1, n); }

 private:
  vector<TreeNode *> generateTrees(int l, int r) {
    if (l > r) return {nullptr};
    vector<TreeNode *> result;
    for (int i = l; i <= r; ++i) {
      for (TreeNode *left : generateTrees(l, i - 1)) {
        for (TreeNode *right : generateTrees(i + 1, r)) {
          result.push_back(new TreeNode(i));
          result.back()->left = left;
          result.back()->right = right;
        }
      }
    }
    return result;
  }
};