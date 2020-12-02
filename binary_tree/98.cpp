// Validate Binary Search Tree
#include <iostream>

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
  bool isValidBST(TreeNode *root) {
    return method1(root, LONG_MIN, LONG_MAX);
    // return method2(root);
  }

 private:
  TreeNode *pre = nullptr;

  bool method1(TreeNode *root, long min, long max) {
    if (!root) return true;
    if (root->val <= min || root->val >= max) return false;
    return method1(root->left, min, root->val) &&
           method1(root->right, root->val, max);
  }

  bool method2(TreeNode *root) {
    if (!root) return true;
    if (!method2(root->left)) return false;
    if (pre && pre->val >= root->val) return false;
    pre = root;
    return method2(root->right);
  }
};