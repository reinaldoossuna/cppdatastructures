#include "singly_ll.h"

using node = singly_ll_node;
using node_ptr = node*;

void singly_ll::push_front(int val)
{
  auto new_node = new node{val,NULL};
  if(head != NULL)
    new_node->next = head;
  head = new_node;
}

void singly_ll::pop_front()
{
  auto first = head;
  if(head)
  {
    head = head->next;
    delete first;
  }
  else
  {
    throw "Empty";
  }
}

singly_ll_iterator& singly_ll_iterator::operator++()
{
  ptr = ptr->next;
  return *this;
}

singly_ll_iterator singly_ll_iterator::operator++(int)
{
  singly_ll_iterator result = *this;
  ++(*this);
  return result;
}

singly_ll::singly_ll(const singly_ll& other): head(NULL)
{
  if(other.head)
  {
    head = new node;
    auto cur = head;
    auto it = other.begin();
    while(true)
    {
      cur->data = *it;
      auto tmp = it;
      ++tmp;
      if(tmp == other.end())
        break;
      cur->next = new node;
      cur = cur->next;
      it = tmp;
    }
  }
}

singly_ll::singly_ll(const std::initializer_list<int>& ilist): head(NULL)
{
  for(auto it = std::rbegin(ilist); it != std::rend(ilist); it++)
  {
    push_front(*it);
  }
}
