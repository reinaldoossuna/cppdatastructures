#pragma once
#include <iostream>
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
 public:
  using node_ptr = std::shared_ptr<Node>;
  node_ptr find(int value);
  void insert(int value);
  void inorder();
  node_ptr successor(node_ptr start);
  void delete_value(int value);

 private:
  node_ptr root;
  node_ptr delete_helper(node_ptr node, int value);
  node_ptr find_helper(node_ptr node, int value);
  void insert_helper(node_ptr node, int value);
  void inorder_helper(node_ptr node);
};
