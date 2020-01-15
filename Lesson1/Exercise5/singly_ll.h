#include <iostream>
#include <algorithm>

struct singly_ll_node {
  int data;
  singly_ll_node* next;
};

using node = singly_ll_node;
using node_ptr = node*;

struct singly_ll_iterator {
 private:
  node_ptr ptr;
 public:
  explicit singly_ll_iterator(node_ptr p) : ptr(p) {}
  int& operator*() {return ptr->data;}
  node_ptr get() {return ptr;}
  singly_ll_iterator& operator++();
  singly_ll_iterator operator++(int);
    friend bool operator==(const singly_ll_iterator& left,          \
                           const singly_ll_iterator& right) {
      return left.ptr == right.ptr;
    }
    friend bool operator!=(const singly_ll_iterator& left,          \
                           const singly_ll_iterator& right) {
      return left.ptr != right.ptr;
    }
};

class singly_ll {
 public:
  node_ptr ptr;

  singly_ll();
  singly_ll(const singly_ll& other);
  explicit singly_ll(const std::initializer_list<int>& ilist);

  void push_front(int);
  void pop_front();
  singly_ll_iterator begin() const {
      return singly_ll_iterator(head);}
    singly_ll_iterator end() const {
      return singly_ll_iterator(NULL);}

 private:
  node_ptr head;
};
