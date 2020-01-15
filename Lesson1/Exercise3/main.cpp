#include <iostream>
#include <forward_list>
#include "./lib.h"

int main() {
    std::forward_list<citizen> citizens = {{"BTight", 22}, \
                                           {"Bobby", 25},  \
                                           {"Massiv", 33}, \
                                           {"Criolo", 44}, \
                                           {"Bua", 17}};
    auto citizens_copy = citizens;
    std::cout << "All the citizens: \n";
    cout_each_elem(citizens);


    std::cout << "Eligible citizens for voting: \n";
    citizens.remove_if(
        [](const citizen& c) {
          return (c.age < 18);
        });
    cout_each_elem(citizens);

    std::cout << "Citizens that will be eligible for voting next year: \n";
    citizens_copy.remove_if(
        [](const citizen& c) {
        return (c.age != 17);
        });
    cout_each_elem(citizens_copy);
}
