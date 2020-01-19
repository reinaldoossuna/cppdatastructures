#include <iostream>
#include <functional>
#include "./cuckoo_hash.h"

int main() {
  hash::HashCuckoo map(3, 5);
  map.print();

  map.insert(10);
  map.insert(20);
  map.insert(30);

  map.insert(104);
  map.insert(2);
  map.insert(70);
  map.insert(9);
  map.insert(90);
  map.insert(2);
  map.insert(7);
  map.insert(101);
  map.insert(5);

  std::cout << std::endl;

  map.print();

  std::cout << std::endl;
  map.insert(14);  // This will cause cycle.
}
