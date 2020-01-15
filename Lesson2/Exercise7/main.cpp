#include <iostream>
#include "./org_tree.h"

void try_to_add(Tree t, const std::string& f, const std::string& s) {
  if (t.insert(f, s))
    std::cout << "Added " << s << " in the tree" << std::endl;
  else
    std::cout << "Couldn't add " << s << " in the tree" << std::endl;
}

int main() {
  Tree tree = Tree::create_tree("CEO");
  tree.insert("CEO", "Deputy Director");
  try_to_add(tree, "Deputy Director", "IT Head");
  try_to_add(tree, "Deputy Director", "Marketing Head");
  try_to_add(tree, "IT Head", "Security Head");
  try_to_add(tree, "IT Head", "App Development Head");
  try_to_add(tree, "Marketing Head", "Public relations Head");
  try_to_add(tree, "Deputy Director", "Finance Head");
}
