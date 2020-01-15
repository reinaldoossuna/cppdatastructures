#include <memory>

struct Node {
  int data;
  std::shared_ptr<Node> left;
  std::shared_ptr<Node> right;

  explicit Node(const int& value):data(value),  \
                                  left(nullptr),    \
                                  right(nullptr) {}
};

class Binary_tree {
 private:
  using node_ptr = std::shared_ptr<Node>;
  node_ptr root;

  node_ptr find_helper(node_ptr node, int value) {
    if (node == nullptr)
      return nullptr;

    if (node->data == value)
      return node;

    if (value < node->data)  // Left branch is Less
      find_helper(node->left, value);
    else  // riGht branch is Greater
      find_helper(node->right, value);

    return nullptr;  // make lint happy
  }

  void insert_helper(node_ptr node, int value) {
    if (value < node->data) {
      if (!node->left)
        node->left = node_ptr(new Node{value});
      else
        insert_helper(node->left, value);
    } else {
      if (!node->right)
        node->right = node_ptr(new Node{value});
      else
        insert_helper(node->right, value);
    }
  }
  void inorder_helper(node_ptr node) {
    if (!node)
        return;

    inorder_helper(node->left); //Visit the left subtree
    inorder_helper(node->right); // Visit the right subtree
  }

 public:
  node_ptr find(int value) {
    return find_helper(root, value);
  }

  void insert(int value) {
    if(!root)
        root = node_ptr(new Node(value));
    else
        insert_helper(root, value);
  }
  void inorder() {
    inorder_helper(root);
  }

  node_ptr successor(node_ptr start) {
    auto current = start->right;
    while(current && current->left)
        current = current-> left;
    return current;
  }

  void delete_value(int value) {
    root = delete_helper(root, value);
  }

private:

  node_ptr delete_helper(node_ptr node, int value) {
    if(!node)
      return nullptr;

    if(value < node->data){
      node->left = delete_helper(node->left, value);
    } else if(value > node->data) {
      node->right = delete_helper(node->right, value);
    } else {  // Either both children are absent or only left child is absent
      if (!node->left) {
        return node->right;
      }
      if (!node->right) {  //Only right child is absent
        return node->left;
      }
      auto successor_node = successor(node);
      node->data = successor_node->data;
      // Delete the successor from right subtree, since it will always be in the right subtree
      node->right = delete_helper(node->right, successor_node->data);
    }
    return node;
  }
};

