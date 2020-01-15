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
  print(25);
  print(100);
  map.print_hash();
  std::cout << std::endl;
  map.insert(100);
  print(100);
  map.print_hash();
  std::cout << std::endl;
  map.erase(25);
  map.print_hash();
  std::cout << std::endl;
}
