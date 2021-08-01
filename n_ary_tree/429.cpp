// N-ary Tree Level Order Traversal
#include <queue>
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
  vector<vector<int>> levelOrder(Node* root) {
    if (!root) return {};
    vector<vector<int>> result;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
      result.push_back({});
      int size = q.size();
      while (size--) {
        Node* node = q.front();
        q.pop();
        result.back().push_back(node->val);
        for (auto child : node->children) {
          q.push(child);
        }
      }
    }

    return result;
  }
};

// class Solution {
//  public:
//   vector<vector<int>> levelOrder(Node* root) {
//     vector<vector<int>> result;
//     preOrder(root, 0, result);
//     return result;
//   }

//  private:
//   void preOrder(Node* root, int d, vector<vector<int>>& result) {
//     if (root == nullptr) return;
//     while (result.size() <= d) result.push_back({});
//     result[d].push_back(root->val);
//     for (auto child : root->children) {
//       preOrder(child, d + 1, result);
//     }
//   }
// };