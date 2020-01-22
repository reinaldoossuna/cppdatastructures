#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include "../Exercise20/quick_sort.h"
#include "../Exercise19/merge_sort.h"

template<class T>
auto find_median(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end) {
  quick_sort<T>(begin, end);

  //  in case the of odd vector, just take the first median
  auto median = begin + std::ceil(std::distance(begin, end)/2);
  return median;
}

template<class T>
auto partition_using_given_pivot(typename std::vector<T>::iterator begin,
                      typename std::vector<T>::iterator end,
                      typename std::vector<T>::iterator pivot) {
  auto left_iter = begin;
  auto right_iter = end ;

  while (true) {
    while (*left_iter <= *pivot && std::distance(left_iter, right_iter))
      ++left_iter;
    while (*right_iter > *pivot && std::distance(left_iter, right_iter))
      --right_iter;
    if (left_iter == right_iter)
      break;
    else
      std::iter_swap(left_iter, right_iter);
  }
  if (*pivot > *right_iter)
    std::iter_swap(begin, right_iter);

  std::cout << *pivot <<std::endl;
  for (auto i = begin ; i != end; i++)
    std::cout << *i << "\t";
  std::cout <<std::endl;

  return right_iter;
}

template<class T>
typename std::vector<T>::iterator linear_time_select(typename std::vector<T>::iterator begin, \
                                                     typename std::vector<T>::iterator end, \
                                                     int i) {
  auto size = std::distance(begin, end);
  if (size > 0 && i < size) {
    auto num_vectors = std::ceil(size / 5.0);

    std::vector<T> M;
    for (auto j = 0; j < num_vectors; ++j) {
      auto b = begin + (j * 5);
      auto last = (j * 5) + 4;

      //  the last vector could have a size less than 5
      auto l = begin + last;
      if (last > size)
        l = end;

      M.push_back(*find_median<T>(b, l));
    }
    // Recusrvely find the median
    auto median_of_medians = (M.size() == 1) ? M.begin() : linear_time_select<T>(M.begin(), M.end() - 1, M.size() / 2);

    auto partition_iter = partition_using_given_pivot<T>(begin, end, median_of_medians);
    auto k = std::distance(begin, partition_iter) + 1;

    if (k == i)
      return partition_iter;
    else if (k > i)
      return linear_time_select<T>(begin, partition_iter - 1, i);
    else if (k < i)
      return linear_time_select<T>(partition_iter + 1, end, i-k);
  }
  return begin;
}
