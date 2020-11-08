// Binary Tree Level Order Traversal
#include <iostream>
#include <stack>
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
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (!root) return {};
    vector<vector<int>> v;
    vector<TreeNode *> current, next;
    current.push_back(root);
    while (!current.empty()) {
      v.push_back({});
      for (TreeNode *node : current) {
        v.back().push_back(node->val);
        if (node->left) {
          next.push_back(node->left);
        }
        if (node->right) {
          next.push_back(node->right);
        }
      }
      current.swap(next);
      next.clear();
    }
    return v;
  }
};
