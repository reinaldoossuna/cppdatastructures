#include <iostream>
#include <forward_list>
#include <vector>

int main() {
  std::vector<std::string> vec = { "Lewis Hamilton",                    \
                                   "Lewis Hamilton",                    \
                                   "Nico Roseberg",                     \
                                   "Sebastian Vettel",                  \
                                   "Lewis Hamilton",                    \
                                   "Sebastian Vettel",                  \
                                   " Sebastian Vettel",                 \
                                   "Sebastian Vettel",                  \
                                   "Fernando Aloson"};
  auto it = vec.begin();

  std::cout << "Latest winner is: " << *it << std::endl;

  it +=8;
  std::cout << "Winner before 8 years was: " << *it << std::endl;

  advance(it, -3);
  std::cout << "Winner before 3years of that was: " << *it << std::endl;

  std::forward_list<std::string> fwd(vec.begin(), vec.end());
  auto it1 = fwd.begin();

  std::cout << "Latest winner is: " << *it1 << std::endl;

  advance(it1, 5);
  std::cout << "Winner before 5 years was: " << *it1 << std::endl;
}
