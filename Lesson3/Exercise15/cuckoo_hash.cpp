#include "./cuckoo_hash.h"

namespace hash {

HashTable::HashTable(int size)
    : size_(size) {
  data = std::vector<int>(size, -1);
  func = [=](int key){return key % size;};
}

std::vector<int>::iterator HashTable::lookup(int key) {
  auto hash = this->func(key);
  if (data[hash] == key) {
    return data.begin() + hash;
  }
  return data.end();
}

bool HashTable::has(int key) {
  return lookup(key) != data.end();
}

bool HashTable::erase(int key) {
  auto posistion = lookup(key);
  if (posistion != data.end()) {
    *posistion = -1;
    return true;
  }
  return false;
}

int HashTable::insert(int key) {
  auto hash = this->func(key);
  if (data[hash] == -1) {
    data[hash] = key;
    return -1;
  } else {
    int old = data[hash];
    data[hash] = key;
    return old;
  }
}

// TODO(reinaldo): rehash if there is data;
void HashTable::set_func(std::function<int(int)> foo) {
  func = foo;
}

void HashTable::print() {
  for (auto key : data)
    std::cout << key << "\t";
  std::cout << std::endl;
}

HashCuckoo::HashCuckoo(int ntables, int size)
    : size_(size), ntables_(ntables) {
  for (int i = 0; i < ntables; i++)
    tables.push_back(HashTable(size));

  // TODO(reinaldo): set some common list of hash func to set here
  tables[1].set_func([](int key) {
                    return key % 7;
                  });

  tables[2].set_func([](int key) {
                   return (key / 7) % 7;
                 });
}
bool HashCuckoo::has(int key) {
  for (auto table : tables) {
    if (table.has(key))
      return true;
  }
  return false;
}

void HashCuckoo::erase(int key) {
  if (this->has(key)) {
    for (auto table : tables) {
      if (table.erase(key))
        return;
    }
  }
  std::cout << "Key " << key << " not found." << std::endl;
}

void HashCuckoo::insert(int key) {
  insert_helper(key, 0, 0);
}

void HashCuckoo::insert_helper(int key, int count, int table) {
  if (count >= size_) {
    std::cout << "Cycle detected, while inserting " << key << ". Rehashing required" << std::endl;
    return;
  }

  auto insert_result = tables[table].insert(key);
  if (insert_result == -1) {
      std::cout << "Inserted key " << key << " in table " << table << std::endl;
  } else {
      std::cout << "Inserted key " << key << " in table " << table << "by replacing " << insert_result << std::endl;
      if (table >= ntables_ - 1)
        table = -1;
      insert_helper(insert_result, count + 1, table + 1);
  }
}

void HashCuckoo::print() {
  std::cout << "Index: ";
  for (int i = 0; i < size_; i++)
    std::cout << i << "\t";
  std::cout << std::endl;

  for (int i = 0; i < ntables_; i++) {
    std::cout << "DATA" << i << ": ";
    tables[i].print();
  }
  std::cout << std::endl;
}
}  // namespace hash
