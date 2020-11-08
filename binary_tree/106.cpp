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
    if (preorder.empty() || inorder.empty() ||
        preorder.size() != inorder.size()) {
      return nullptr;
    }
    auto root = find(inorder.begin(), inorder.end(), preorder.front());
    vector<int> leftInorder = {inorder.begin(), root};
    vector<int> rightInorder = {root + 1, inorder.end()};
    vector<int> leftPreorder = {preorder.begin() + 1,
                                preorder.begin() + 1 + leftInorder.size()};
    vector<int> rightPreorder = {preorder.begin() + leftInorder.size() + 1,
                                 rightPreorder.end()};
    return new TreeNode(*root, buildTree(leftPreorder, leftInorder),
                        buildTree(rightPreorder, rightInorder));
  }
};