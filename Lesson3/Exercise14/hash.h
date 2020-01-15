#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using uint = unsigned int;

class hash_map {
 public:
  explicit hash_map(size_t n) {
    data.resize(n);
  }
  void insert(uint value) {
    int n = data.size();
    data[value % n].push_back(value);
    std::cout << "Inserted" << value << std::endl;
  }
  bool find(uint value) {
    int n = data.size();
    auto& entries = data[value % n];
    return std::find(entries.begin(), entries.end(), value) != entries.end();
  }
  void erase(uint value) {
    int n = data.size();
    auto& entries = data[value % n];
    auto iter =  std::find(entries.begin(), entries.end(), value);
    if (iter != entries.end()) {
      entries.erase(iter);
      std::cout << "Removed" << value << std::endl;
    }
  }
  void print_hash() {
    for (auto ls : data) {
      for (auto v : ls)
        std::cout << v << "\t";
      std::cout << std::endl;
    }
  }

 private:
  std::vector<std::list<int>> data;
};
