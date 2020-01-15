#include <iostream>
#include "./binary_tree.h"

int main() {
  Binary_tree tree;
  tree.insert(12);
  tree.insert(10);
  tree.insert(20);
  tree.insert(8);
  tree.insert(11);
  tree.insert(15);
  tree.insert(28);
  tree.insert(4);
  tree.insert(2);

  std::cout << "Inorder: ";
  tree.inorder();
  std::cout << std::endl;
  tree.delete_value(12);
  std::cout << "Inorder after deleteing 12: ";
  tree.inorder();
  std::cout << std::endl;
  if (tree.find(12)) {
      std::cout << "Element 12 is present in the tree" << std::endl;
  } else {
      std::cout << "Element 12 is NOT present in the tree" << std::endl;
  }
}
