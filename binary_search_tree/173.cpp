// Binary Search Tree Iterator
#include <iostream>
#include <stack>

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

class BSTIterator {
 public:
  BSTIterator(TreeNode *root) { addNode(root); }

  /** @return the next smallest number */
  int next() {
    TreeNode *node = s.top();
    s.pop();
    addNode(node->right);
    return node->val;
  }

  /** @return whether we have a next smallest number */
  bool hasNext() { return !s.empty(); }

 private:
  stack<TreeNode *> s;

  void addNode(TreeNode *node) {
    while (node) {
      s.push(node);
      node = node->left;
    }
  }
};