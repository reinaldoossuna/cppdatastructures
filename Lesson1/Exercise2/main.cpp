#include <iostream>
#include "./general_purpose_struct.h"

int main() {
  // this return
  // 1 0 97 3.2 0
  // everthing can be converted to float
  auto data = build_array(1, 0u, 'a', 3.2f, false);

  for (auto i : data)
    std::cout << i << " ";
  std::cout << std::endl;

  // This return a error because there is no common type
  // auto data2 = build_array(1, "Packt", 2.0);
}
