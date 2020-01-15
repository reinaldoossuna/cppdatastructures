#include "./stream.h"

int main() {
  Median med;
  med.insert(1);
  std::cout << "Median after insert " << med.get() << std::endl;
  med.insert(5);
  std::cout << "Median after insert " << med.get() << std::endl;
  med.insert(2);
  std::cout << "Median after insert " << med.get() << std::endl;
  med.insert(10);
  std::cout << "Median after insert " << med.get() << std::endl;
  med.insert(40);
  std::cout << "Median after insert " << med.get() << std::endl;
}
