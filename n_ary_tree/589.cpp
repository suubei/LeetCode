// N-ary Tree Preorder Traversal
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
  vector<int> postorder(Node* root) {
    vector<int> result = vector<int>();
    postorder(root, result);
    return result;
  }

 private:
  void postorder(Node* root, vector<int>& result) {
    if (!root) return;
    for (const auto& node : root->children) {
      postorder(node, result);
    }
    result.push_back(root->val);
  }
};