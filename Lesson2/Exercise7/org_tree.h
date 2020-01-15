#pragma once

#include <string>
#include <memory>
#include <iostream>

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
};
