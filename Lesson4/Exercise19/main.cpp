#include <iostream>
#include "./merge_sort.h"


int main() {
  std::vector<int> S1{ 45, 1, 3, 1, 2, 3, 45, 5, 1, 2, 44, 5, 7 };
  std::cout << S1 << std::endl;
  auto sorted_S1 = merge_sort<int>(S1);
  std::cout << sorted_S1;
}
