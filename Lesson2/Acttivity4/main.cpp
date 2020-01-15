#include <iostream>
#include "./file_system.h"

int main() {
    Filesystem n;
    n.add("home", true);
    n.add("boot", true);
    n.add("root", true);
    n.add("etc" , true);
    n.add("bin" , true);
    std::cout << "ls /: \n" <<std::endl;
    n.list();

    std::cout << "ls /home/me: \n" <<std::endl;
    n.add("home/me", true);
    n.add("home/me/Documents", true);
    n.add("home/me/.profile", false);
    n.change_dir("home/me");
    n.list();
}
