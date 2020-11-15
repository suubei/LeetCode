// Construct Binary Tree from Preorder and Inorder Traversal
#include <algorithm>
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
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int rootIndex = postorder.size() - 1;
    return build(inorder, postorder, 0, inorder.size() - 1, &rootIndex);
  }

  TreeNode *build(vector<int> &inorder, vector<int> &postorder, int start,
                  int end, int *rootIndex) {
    if (start > end) {
      return NULL;
    } else {
      TreeNode *tree = new TreeNode(postorder[(*rootIndex)--]);
      if (end != start) {
        int index = search(inorder, start, end, tree->val);
        tree->right = build(inorder, postorder, index + 1, end, rootIndex);
        tree->left = build(inorder, postorder, start, index - 1, rootIndex);
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
