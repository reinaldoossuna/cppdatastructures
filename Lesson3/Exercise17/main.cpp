#include "./bloom_filters.h"

int main() {
    BloomFilter bf(11);
    bf.insert(100);
    bf.insert(54);
    bf.insert(82);
    bf.lookup(5);
    bf.lookup(50);
    bf.lookup(2);
    bf.lookup(100);
    bf.lookup(8);
    bf.lookup(65);
}
