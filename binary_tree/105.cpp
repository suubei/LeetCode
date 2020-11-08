// Construct Binary Tree from
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
    if (inorder.empty() || postorder.empty() ||
        inorder.size() != postorder.size()) {
      return nullptr;
    }
    auto root = find(inorder.begin(), inorder.end(), postorder.back());
    vector<int> leftInorder = {inorder.begin(), root};
    vector<int> rightInorder = {root + 1, inorder.end()};
    vector<int> leftPostorder = {postorder.begin(),
                                 postorder.begin() + leftInorder.size()};
    vector<int> rightPostorder = {postorder.begin() + leftInorder.size(),
                                  postorder.end() - 1};
    return new TreeNode(*root, buildTree(leftInorder, leftPostorder),
                        buildTree(rightInorder, rightPostorder));
  }
};