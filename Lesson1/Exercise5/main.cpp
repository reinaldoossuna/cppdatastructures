#include "./singly_ll.h"

int main() {
  singly_ll sll = {1, 2, 3};
  sll.push_front(0);

  std::cout << "First list: ";
  for (auto i : sll)
    std::cout << i << " ";
  std::cout << std::endl;

  auto sll2 = sll;
  sll2.push_front(-1);

  std::cout << "Second list: ";
  for (auto i : sll2)
    std::cout << i << " ";
  std::cout << std::endl;

  std::cout << "First list after deep copy: ";
  for (auto i : sll)
    std::cout << i << " ";
  std::cout << std::endl;
}
