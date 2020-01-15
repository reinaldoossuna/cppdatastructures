#pragma once

#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


struct Node {
  std::string name_;
  bool is_dir_;
  std::string permission_;
  std::vector<std::shared_ptr<Node>> children;

  explicit Node(const std::string& name,          \
                bool is_dir,                      \
                const std::shared_ptr<Node>& parent):
    name_(name),                                                  \
    is_dir_(is_dir) {
    if (is_dir_) {
        permission_ = "rwxr-xr-x";
        /*auto dot = std::make_shared<Node>(*this);
        children.push_back(dot);

        auto dotdot = std::make_shared<Node>(*parent);
        children.push_back(dotdot);
        */
    } else {
        permission_ = "rw-r--r--";
        children.resize(0);
    }
  }

  // root constructor
  explicit Node(const std::string& name, bool is_dir):
    name_(name),                                                  \
    is_dir_(is_dir) {
      if (is_dir)
        permission_ = "rwxr-xr-x";
      else
        permission_ = "rw-r--r--";

      /*
      auto dot = std::make_shared<Node>(*this);
      children.push_back(dot);
      */
    }
};

class Filesystem {
 public:
  using node_ptr = std::shared_ptr<Node>;

  Filesystem(): root(node_ptr(new Node{ "/", true})), cwd(root) {
  }
  node_ptr find(const std::string& path) {
    if (path[0] == '/')
      find_helper(root, path.substr(1));
    else
      find_helper(cwd, path);
    return nullptr;  // make lint happy
  }
  bool add(const std::string& path, bool is_dir) {
    if (path[0] == '/')
      return add_helper(root, path.substr(1), is_dir);
    else
      return add_helper(cwd, path, is_dir);
  }
  bool change_dir(const std::string& path) {
    if (path[0] == '/')
      return change_dir_helper(root, path.substr(1));
    else
      return change_dir_helper(cwd, path);
  }
  void list() {  // ls
    for (auto child : cwd->children) {
      std::cout << (child->is_dir_ ? 'd' : '-');
      std::cout << child->permission_;
      std::cout << "\t";
      std::cout << child->name_ << std::endl;
    }
  }
  void print_cwd() {  // pwd
    std::cout << cwd->name_ << std::endl;
  }

 private:
  node_ptr root;
  node_ptr cwd;

  node_ptr find_helper(const node_ptr& dir, const std::string& path) {
    if (path.empty())
      return dir;

    auto pos = path.find("/");

    std::string curr_dir = pos == std::string::npos ? path : path.substr(0, pos);
    std::string rest_path = pos == std::string::npos ? "" : path.substr(pos + 1);

    auto found = std::find_if(dir->children.begin(), dir->children.end(),
                              [&](const node_ptr child) {
                                return child->name_ == curr_dir;
                              });
    if (found != dir->children.end())
      return find_helper(*found, rest_path);

    return nullptr;
  }

  bool add_helper(node_ptr node, std::string path, bool is_dir) {
    if (!node->is_dir_) {
      std::cout << node->name_ << "is a file!" << std::endl;
      return false;
    }

    auto pos = path.find("/");
    if (pos == std::string::npos) {
      if (find_helper(node, path)) {
        std::cout << path << "alread exists in " << node->name_ << std::endl;
        return false;
      }

      auto new_node = node_ptr(new Node{path, is_dir, node});
      node->children.push_back(new_node);
      return true;
    } else {
      auto next_path = path.substr(pos+1);
      auto next_node = find_helper(node, path.substr(0, pos));

      if (!next_node) {
        std::cout << next_path << " not exists in " << node->name_ << std::endl;
        return false;
      }
      return add_helper(next_node, next_path, is_dir);
    }
  }

  bool change_dir_helper(node_ptr node, const std::string& path) {
    if (!node->is_dir_) {
      std::cout << node->name_ << " is not a directory" <<std::endl;
      return false;
    }

    auto pos = path.find("/");
    if (pos == std::string::npos) {
      cwd = find_helper(node, path);
      return true;
    }

    auto next_path = path.substr(pos+1);
    auto next_node = find_helper(node, path.substr(0, pos));
    if (!next_node) {
      std::cout << next_path << " is not a directory in" << node->name_ <<std::endl;
      return false;
    }

    return change_dir_helper(next_node, next_path);
  }
};
