#pragma once

#include <iostream>
#include <functional>
#include <vector>

namespace hash {

class HashCuckoo;

class HashTable {
 private:
  std::vector<int> data;
  int size_;
  std::function<int(int)> func;

 public:
  friend class HashCuckoo;

  explicit HashTable(int size);
  std::vector<int>::iterator lookup(int key);
  bool has(int key);
  bool erase(int key);
  int insert(int key);
  void set_func(std::function<int(int)> foo);
  void print();
};

class HashCuckoo {
 public:
  explicit HashCuckoo(int ntables, int size);
  bool has(int key);
  void erase(int key);
  void insert(int key);
  void print();

 private:
  std::vector<HashTable> tables;
  void insert_helper(int key, int count, int table);
  int size_;
  int ntables_;
};

}  // namespace hash
