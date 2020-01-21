#pragma once

#include <vector>
#include <algorithm>
#include <random>

template<class T>
auto partition_random(typename std::vector<T>::iterator begin,
               typename std::vector<T>::iterator last) {
  std::random_device rd;
  std::seed_seq      seed{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
  std::mt19937       eng(seed);
  auto size = std::distance(begin, last);
  std::uniform_int_distribution<int> uniform_dist(0, size);

  auto random_iter = uniform_dist(eng);

  auto pivot_val = *(begin+random_iter);
  auto left_iter = begin;
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
void quick_sort_random(typename std::vector<T>::iterator begin,
                typename std::vector<T>::iterator last) {
  if (std::distance(begin, last) >= 1) {
    auto partition_iter = partition_random<T>(begin, last);

    quick_sort_random<T>(begin, partition_iter-1);
    quick_sort_random<T>(partition_iter, last);
  }
}
