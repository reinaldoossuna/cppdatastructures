#include <iostream>
#include "./hash.h"

int main() {
  hash_map map(7);

  auto print = [&](int value) {
                 if (map.find(value))
                   std::cout << value << "found in the has map";
                 else
                   std::cout << value << "NOT found in the has map";
                 std::cout << std::endl;
               };

  map.insert(2);
  map.insert(25);
  map.insert(290);
  map.print_hash();
  map.insert(100);
  map.insert(55);
  map.print_hash();
  map.erase(2);
  map.insert(39);
  map.insert(53);
  map.insert(283);
  map.print_hash();
  return 0;
}
