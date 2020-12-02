// Serialize and Deserialize Binary Tree
#include <sstream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    ostringstream out;
    serialize(root, out);
    return out.str();
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    istringstream in(data);
    return deserialize(in);
  }

 private:
  enum STATUS {
    ROOT_NULL = 0x0,
    ROOT = 0x1,
    ROOT_LEFT = 0x2,
    ROOT_RIGHT = 0x4
  };
  void serialize(TreeNode* root, ostringstream& out) {
    char status = 0;
    if (root) status |= ROOT;
    if (root && root->left) status |= ROOT_LEFT;
    if (root && root->right) status |= ROOT_RIGHT;
    out.write(&status, sizeof(char));
    if (!root) return;
    out.write(reinterpret_cast<char*>(&root->val), sizeof(root->val));
    if (root->left) serialize(root->left, out);
    if (root->right) serialize(root->right, out);
  }
  TreeNode* deserialize(istringstream& in) {
    char status;
    in.read(&status, sizeof(char));
    if (!status & ROOT) return nullptr;
    auto root = new TreeNode(0);
    in.read(reinterpret_cast<char*>(&root->val), sizeof(root->val));
    root->left = (status & ROOT_LEFT) ? deserialize(in) : nullptr;
    root->right = (status & ROOT_RIGHT) ? deserialize(in) : nullptr;
    return root;
  }
};