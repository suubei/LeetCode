#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (!node) return NULL;
    unordered_set<Node*> s;
    unordered_map<Node*, Node*> m;
    stack<Node*> st;
    st.push(node);
    while (!st.empty()) {
      Node* top = st.top();
      st.pop();
      if (!s.count(top)) {
        s.insert(top);
        if (!m[top]) {
          m[top] = new Node(top->val);
        }
        for (Node*& neighbor : top->neighbors) {
          if (!m[neighbor]) {
            m[neighbor] = new Node(neighbor->val);
          }
          if (!s.count(neighbor)) {
            st.push(neighbor);
          }
          m[top]->neighbors.push_back(m[neighbor]);
        }
      }
    }
    return m[node];
  }
};