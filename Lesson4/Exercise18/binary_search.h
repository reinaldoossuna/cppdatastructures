#pragma once

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <functional>
#include <numeric>

bool linear_search(int N, std::vector<int> *S) {
  for (auto i : *S) {
    if (i == N)
      return true;
  }
  return false;
}

bool binary_search(int N, std::vector<int> *S) {
  auto head = S->begin();
  auto tail = S->end();

  while (true) {
    //    http://www.cplusplus.com/reference/iterator/distance/
    auto range_length = std::distance(head, tail);
    auto median_index = std::floor(range_length / 2);
    auto median = *(head + median_index);

    //  http://www.cplusplus.com/reference/iterator/advance/
    if (median == N) {
      return true;
    } else if (median > N) {
      std::advance(tail, -median_index);
    } else if (median < N) {
      std::advance(head, median_index);
    }
    if (range_length == 1)
      return false;
  }
}

template<class T>
std::vector<T>* create_random_array(int size) {
  std::vector<int>* S = new std::vector<int>(size);

  std::random_device rd;
  std::seed_seq      seed{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
  std::mt19937       eng(seed);
  std::uniform_int_distribution<int> uniform_dist(1, size);

  std::generate(S->begin(), S->end(), std::bind(uniform_dist, eng));

  return S;
}

void large_search_test(int size, int N) {
  auto *S = create_random_array<int>(size);

  std::sort(S->begin(), S->end());

  auto begin = std::chrono::high_resolution_clock::now();
  binary_search(N, S);
  auto end = std::chrono::high_resolution_clock::now();

  std::cout << "Time taken by binary search = " <<
      std::chrono::duration_cast<std::chrono::nanoseconds>
      (end - begin).count() << " nanoseconds" <<std::endl;

  std::cout << "Element found in set!" << std::endl;

  begin = std::chrono::high_resolution_clock::now();
  linear_search(N, S);
  end = std::chrono::high_resolution_clock::now();

  std::cout << "Time taken by linear search = " <<
      std::chrono::duration_cast<std::chrono::nanoseconds>
      (end - begin).count() << " nanoseconds" << std::endl;
}
