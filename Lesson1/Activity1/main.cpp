/* Copyright 2020 Ossuna  */


#include <iostream>
#include "./playlist.h"

int main() {
    Playlist::Playlist pl;
    pl.insert(1);
    pl.insert(2);
    pl.insert(5);
    pl.insert(8);
    std::cout << "Playlist : ";
    pl.loop_once();

    Playlist::Playlist pl2 = pl;
    pl2.erase(2);
    pl2.erase(12);
    pl2.erase(13);
    pl2.insert(3);
    std::cout << "Second playlist : ";
    pl2.loop_once();
}
