#pragma once

#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
  os << "[";
  for (auto i : v)
    os << i << ", ";
  os << "]\n";
  return os;
}

template<class T>
std::vector<T> merge(const std::vector<T>& vec1, const std::vector<T>& vec2) {
  auto size = vec1.size() + vec2.size();
  std::vector<T> merged;
  merged.reserve(size);

  auto iter1 = vec1.begin();
  auto iter2 = vec2.begin();

  while ((iter1 != vec1.end() && iter2 != vec2.end())) {
    if (*iter1 < *iter2) {
      merged.emplace_back(*iter1);
      ++iter1;
    } else {
      merged.emplace_back(*iter2);
      ++iter2;
    }
  }
  while (iter1 != vec1.end()) {
    merged.emplace_back(*iter1);
    ++iter1;
  }

  while (iter2 != vec2.end()) {
    merged.emplace_back(*iter2);
    ++iter2;
  }

  //  Print each step
  //  std::cout << merged;
  return merged;
}

template<class T>
std::vector<T> merge_sort(const std::vector<T>& vec) {
  if (vec.size() > 1) {
    auto mid_pos = size_t(vec.size() / 2);
    auto left_half = merge_sort<T>(std::vector<T>(vec.begin(), vec.begin() + mid_pos));
    auto right_half = merge_sort<T>(std::vector<T>(vec.begin() + mid_pos, vec.end()));

    return merge<T>(left_half, right_half);
  }
  return vec;
}
