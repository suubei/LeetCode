// Populating Next Right Pointers in Each Node
#include <iostream>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
 public:
  Node* connect(Node* root) {
    Node* cur = root;
    while (cur && cur->left) {
      Node* tmp = cur;
      while (cur) {
        cur->left->next = cur->right;
        if (cur->next) {
          cur->right->next = cur->next->left;
        }
        cur = cur->next;
      }
      cur = tmp->left;
    }
    return root;
  }
};
