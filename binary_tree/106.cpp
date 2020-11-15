// Construct Binary Tree from Inorder and Postorder Traversal
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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int rootIndex = 0;
    return build(preorder, inorder, 0, inorder.size() - 1, &rootIndex);
  }

  TreeNode *build(vector<int> &preorder, vector<int> &inorder, int start,
                  int end, int *rootIndex) {
    if (start > end) {
      return NULL;
    } else {
      TreeNode *tree = new TreeNode(preorder[(*rootIndex)++]);
      if (end != start) {
        int index = search(inorder, start, end, tree->val);
        tree->left = build(preorder, inorder, start, index - 1, rootIndex);
        tree->right = build(preorder, inorder, index + 1, end, rootIndex);
      }
      return tree;
    }
  }

  int search(vector<int> &inorder, int start, int end, int root) {
    for (int i = end; i >= start; i--) {
      if (inorder[i] == root) {
        return i;
      }
    }
    return end;
  }
};