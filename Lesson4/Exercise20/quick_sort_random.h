#pragma once

#include <vector>
#include <algorithm>
#include <random>

template<class T>
auto partition_random(typename std::vector<T>::iterator begin,  \
                      typename std::vector<T>::iterator end) {
  auto pivot = *begin;
  auto left_iter = begin + 1;
  auto right_iter = end;

  while (true) {
    while (*left_iter <= pivot && std::distance(left_iter, right_iter))
      ++left_iter;
    while (*right_iter > pivot && std::distance(left_iter, right_iter))
      --right_iter;
    if (left_iter == right_iter)
      break;
    else
      std::iter_swap(left_iter, right_iter);
  }
  if (pivot > *right_iter)
    std::iter_swap(begin, right_iter);

  return right_iter;
}

template<class T>
void quick_sort_random(typename std::vector<T>::iterator begin,
                typename std::vector<T>::iterator last) {

  std::minstd_rand0 generator;
  auto size = std::distance(begin, last);
  std::uniform_int_distribution<int> uniform_dist(0, size);
  auto random_iter = uniform_dist(generator);

  std::iter_swap(begin, begin + random_iter);

  if (std::distance(begin, last) >= 1) {
    auto partition_iter = partition_random<T>(begin, last);

    quick_sort_random<T>(begin, partition_iter-1);
    quick_sort_random<T>(partition_iter, last);
  }
}
