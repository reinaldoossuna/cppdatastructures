#pragma once

#include <vector>
#include <algorithm>

template<class T>
auto partition(typename std::vector<T>::iterator begin,
               typename std::vector<T>::iterator last) {
  auto pivot_val = *begin;
  auto left_iter = begin+1;
  auto right_iter = last;

  while (true) {
    while (*left_iter <= pivot_val && std::distance(left_iter, right_iter))
      ++left_iter;
    while (*right_iter > pivot_val && std::distance(left_iter, right_iter))
      --right_iter;
    if (left_iter == right_iter)
      break;
    else
      std::iter_swap(left_iter, right_iter);
  }
  if (pivot_val > *right_iter)
    std::iter_swap(begin, right_iter);

  return right_iter;
}

template<class T>
void quick_sort(typename std::vector<T>::iterator begin,
                typename std::vector<T>::iterator last) {
  if (std::distance(begin, last) >= 1) {
    auto partition_iter = partition<T>(begin, last);

    quick_sort<T>(begin, partition_iter-1);
    quick_sort<T>(partition_iter, last);
  }
}
