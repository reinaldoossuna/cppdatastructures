#pragma once

#include <iostream>
#include <vector>

using uint = unsigned int;

class hash_map {
 public:
  explicit hash_map(size_t n) {
    data = std::vector<int>(n, -1);
  }
  void insert(uint value) {
    int n = data.size();
    data[value % n] = value;
    std::cout << "Inserted" << value << std::endl;
  }
  bool find(uint value) {
    int n = data.size();
    return (data[value % n] == value);
  }
  void erase(uint value) {
    int n = data.size();
    if (data[value % n] == value) {
        data[value % n ] = -1;
        std::cout << "Removed " << value << std::endl;
    }
  }
  void print_hash() {
    for (auto v : data)
      std::cout << v << std::endl;
  }

 private:
  std::vector<int> data;
};
