// Binary Tree Postorder Traversal
#include <algorithm>
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
  vector<int> preorderTraversal(TreeNode *root) {
    stack<TreeNode *> s;
    vector<int> v;
    if (root) {
      s.push(root);
    }
    while (!s.empty()) {
      TreeNode *p = s.top();
      s.pop();
      v.push_back(p->val);
      if (p->left) {
        s.push(p->left);
      }
      if (p->right) {
        s.push(p->right);
      }
    }
    reverse(v.begin(), v.end());
    return v;
  }
};

int main() { return 0; }