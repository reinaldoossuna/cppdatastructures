#include <iostream>
#include <string>
#include "./dynamic_array.h"

struct student {
  std::string name;
  int standard;
};

std::ostream& operator<<(std::ostream& os, const student& s) {
  return (os<<"Name: " << s.name << ", Standard: " << s.standard);
}

int main() {
  int nStudents;
  std::cout << "Enter number of students in class 1:" << std::endl;
  std::cin >> nStudents;

  Dynamic_array<student> class1(nStudents);

  std::string name;
  int standard;

  for (int i = 0; i < nStudents; i++) {
    std::cout << "Enter name and class of student " << i + 1 << ":" << std::endl;
    std::cin >> name >> standard;
    class1[i] = student{name, standard};
  }

  Dynamic_array<student> class2 = Dynamic_array<student>(class1);

  Dynamic_array<student> class3 = class1 + class2;

  for (auto s : class3) {
    std::cout << s << std::endl;
  }
}
