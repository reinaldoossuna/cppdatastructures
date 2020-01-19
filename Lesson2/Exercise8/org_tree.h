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
 public:
  using node_ptr = std::shared_ptr<Node>;
  Tree():root(nullptr) {}
  node_ptr find(const std::string& pos);

  static Tree create_tree(std::string pos);
  bool insert(const std::string& parent_pos, const std::string& pos);
  void level_order();
  void pre_order();
  void in_order();
  void post_order();

 private:
  node_ptr root;
  node_ptr find_helper(node_ptr node, std::string pos);
  void pre_order_helper(node_ptr node);
  void in_order_helper(node_ptr node);
  void post_order_helper(node_ptr node);
};
