#pragma once

#include <algorithm>
#include <iostream>
#include <sstream>

template<class T>
class Dynamic_array {
 private:
  T *data;
  size_t n;

 public:
  explicit Dynamic_array(int n): n(n) { data = new T[n]; }

  Dynamic_array(const Dynamic_array<T> &other): n(other.n) {
    data = new T[n];
    for (int i = 0; i < n; i++)
      this->data[i] = other[i];
  }

  ~Dynamic_array() { delete[] data; }

  T &at(int index) {
    if (index < n)
      return data[index];
    throw "Index out of range";
  }

  size_t size() const { return n; }
  T *begin() const { return data; }
  T *end() const { return data + n; }

  // Overloadings
  T &operator[](int index) const { return data[index]; }
  friend Dynamic_array<T> operator+(const Dynamic_array<T>& arr1, const Dynamic_array<T>& arr2) {
    Dynamic_array<T> result(arr1.size() + arr2.size());
    std::copy(arr1.begin(), arr1.end(), result.begin());
    std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());
    return result;
  }
};
