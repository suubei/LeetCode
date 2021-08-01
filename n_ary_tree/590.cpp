// N-ary Tree Postorder Traversal
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
 public:
  vector<int> preorder(Node* root) {
    vector<int> result = vector<int>();
    preorder(root, result);
    return result;
  }

 private:
  void preorder(Node* root, vector<int>& result) {
    if (!root) return;
    result.push_back(root->val);
    for (const auto& node : root->children) {
      preorder(node, result);
    }
  }
};