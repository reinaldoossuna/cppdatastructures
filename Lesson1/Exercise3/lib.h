#pragma once

#include <iostream>
#include <string>
#include <forward_list>

struct citizen {
    std::string name;
    int age;
};

std::ostream& operator<<(std::ostream& os,      \
                         const citizen& c) {
    return (os << "Name: " << c.name << " Age: "<< c.age );
}

template <typename T>
void cout_each_elem(const std::forward_list<T>& fl) {
    for (auto elem : fl)
        std::cout << elem << " ";
    std::cout << std::endl;
}
