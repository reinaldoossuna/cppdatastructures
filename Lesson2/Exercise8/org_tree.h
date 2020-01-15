#pragma once

#include <string>
#include <memory>
#include <iostream>
#include <queue>

struct Node {
  std::string position;
  std::shared_ptr<Node> left;
  std::shared_ptr<Node> right;

  explicit Node(const std::string& pos):position(pos), left(nullptr), right(nullptr) {}
};

class Tree {
 private:
  using node_ptr = std::shared_ptr<Node>;
  node_ptr root;

  node_ptr find_helper(node_ptr node, std::string pos) {
    if (node == nullptr)
      return nullptr;

    if (node->position == pos)
      return node;

    auto left_found = this->find_helper(node->left, pos);
    if (left_found)
      return left_found;

    return this->find_helper(node->right, pos);
  }

  void pre_order_helper(node_ptr node) {
    if (!node)
      return;
    std::cout << node->position << ", ";
    pre_order_helper(node->left);
    pre_order_helper(node->right);
  }

  void in_order_helper(node_ptr node) {
    if (!node)
      return;
    in_order_helper(node->left);
    std::cout << node->position << ", ";
    in_order_helper(node->right);
  }

  void post_order_helper(node_ptr node) {
    if (!node)
      return;
    post_order_helper(node->left);
    post_order_helper(node->right);
    std::cout << node->position << ", ";
  }

 public:
  Tree():root(nullptr) {}

  node_ptr find(const std::string& pos) {
    return find_helper(this->root, pos);
  }

  static Tree create_tree(std::string pos) {
    Tree tree;
    tree.insert("", pos);
    return tree;
  }

  bool insert(const std::string& parent_pos, const std::string& pos) {
    if (root == nullptr) {
      root = node_ptr(new Node(pos));
      return true;
    } else {
      auto parent_node = this->find(parent_pos);

      if (!parent_node) {
        std::cout << parent_pos << " not in the tree" << std::endl;
        return false;
      }

      if (parent_node->left && parent_node->right) {
        std::cout << parent_pos << "already has 2 subordinates" << std::endl;
        return false;
      } else {
        if (!parent_node->left)
          parent_node->left  = node_ptr(new Node(pos));
        else
          parent_node->right = node_ptr(new Node(pos));
      }
    }
    return true;
  }

  void level_order() {
    if (!this->root)
      return;

    std::queue<node_ptr> q;
    q.push(this->root);

    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size ; ++i) {
        auto current = q.front();
        q.pop();
        std::cout << current->position << ", ";
        if (current->left)
          q.push(current->left);
        if (current->right)
          q.push(current->right);
      }
      std::cout << std::endl;
    }
  }
  void pre_order() {
    pre_order_helper(this->root);
    std::cout << std::endl;
  }
  void in_order() {
    in_order_helper(this->root);
    std::cout << std::endl;
  }
  void post_order() {
    post_order_helper(this->root);
    std::cout << std::endl;
  }
};
