#include "./bloom_filters.h"

BloomFilter::BloomFilter(int n)
    : nBits(n) {
  data = std::vector<bool>(nBits, false);
}

void BloomFilter::lookup(int key) {
  bool result = data[hash(0, key)] & data[hash(1, key)] & data[hash(3, key)];
  if (result) {
    std::cout << key << "may be present" << std::endl;
  } else {
    std::cout << key << "is not present" << std::endl;
  }
}

void BloomFilter::insert(int key) {
  data[hash(0, key)] = true;
  data[hash(1, key)] = true;
  data[hash(2, key)] = true;
  std::cout << key << "inserted" << std::endl;
}

int BloomFilter::hash(int num, int key) {
  switch (num) {
    case 0:
      return key % nBits;
    case 1:
      return (key / 7) % nBits;
    case 2:
      return (key / 11) % nBits;
  }
  return 0;
}
