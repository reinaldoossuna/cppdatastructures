#include "./binary_tree.h"

using node_ptr = std::shared_ptr<Node>;


node_ptr Binary_tree::find(int value) {
  return find_helper(root, value);
}

void Binary_tree::insert(int value) {
  if (!root)
    root = node_ptr(new Node(value));
  else
    insert_helper(root, value);
}

void Binary_tree::inorder() {
  inorder_helper(root);
}

node_ptr Binary_tree::successor(node_ptr start) {
  auto current = start->right;
  while (current && current->left)
      current = current-> left;
  return current;
}

void Binary_tree::delete_value(int value) {
  root = delete_helper(root, value);
}

node_ptr Binary_tree::delete_helper(node_ptr node, int value) {
  if (!node)
    return nullptr;

  if (value < node->data) {
    node->left = delete_helper(node->left, value);
  } else if (value > node->data) {
    node->right = delete_helper(node->right, value);
  } else {  // Either both children are absent or only left child is absent
    if (!node->left) {
      return node->right;
    }
    if (!node->right) {  // Only right child is absent
      return node->left;
    }
    auto successor_node = successor(node);
    node->data = successor_node->data;
    // Delete the successor from right subtree, since it will always be in the right subtree
    node->right = delete_helper(node->right, successor_node->data);
  }
  return node;
}

node_ptr Binary_tree::find_helper(node_ptr node, int value) {
  if (node == nullptr)
    return nullptr;

  if (node->data == value)
    return node;

  if (value < node->data)  // Left branch is Less
    find_helper(node->left, value);
  else  // riGht branch is Greater
    find_helper(node->right, value);

  return nullptr;  // make lint happt
}

void Binary_tree::insert_helper(node_ptr node, int value) {
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

void Binary_tree::inorder_helper(node_ptr node) {
  if (!node)
      return;

  inorder_helper(node->left);  // Visit the left subtree
  std::cout << node->data << " ";
  inorder_helper(node->right);  // Visit the right subtree
}
