#pragma once

#include <iostream>
#include <vector>

class BloomFilter {
 public:
  explicit BloomFilter(int n);
  void lookup(int key);
  void insert(int key);

 private:
  std::vector<bool> data;
  int nBits;
  int hash(int num, int key);
};
