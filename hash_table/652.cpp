#include <iostream>
#include <unordered_map>
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
  int getId(TreeNode *node, unordered_map<long, pair<int, int>> &m,
            vector<TreeNode *> &result) {
    if (!node) return 0;
    long key = (static_cast<long>(static_cast<unsigned>(node->val)) << 32) +
               (getId(node->left, m, result) << 16) +
               getId(node->right, m, result);
    auto &p = m[key];
    if (p.second++ == 0) {
      p.first = m.size();
    } else if (p.second == 2) {
      result.push_back(node);
    }
    return p.first;
  }

  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    unordered_map<long, pair<int, int>> m;
    vector<TreeNode *> result;
    getId(root, m, result);
    return result;
  }
};
