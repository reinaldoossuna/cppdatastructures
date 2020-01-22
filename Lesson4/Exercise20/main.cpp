#include <iostream>
#include <chrono>
#include <algorithm>

#include "../Exercise18/binary_search.h"
#include "../Exercise19/merge_sort.h"
#include "./quick_sort.h"
#include "./quick_sort_random.h"

int main() {
  std::vector<int> *S1;
  std::vector<int> *S2;
  S2 = create_random_array<int>(10000);
  S1 = create_random_array<int>(10000);

//  std::sort(S1->begin(), S1->end());  // Worst case scenario for quick sort O(n^2)


  auto begin = std::chrono::high_resolution_clock::now();
  merge_sort<int>(*S1);
  auto end = std::chrono::high_resolution_clock::now();

  std::cout << "Time taken by merge sort = " <<
      std::chrono::duration_cast<std::chrono::microseconds>
      (end - begin).count() << " microseconds" <<std::endl;

  begin = std::chrono::high_resolution_clock::now();
  quick_sort<int>(S1->begin(), S1->end());
  end = std::chrono::high_resolution_clock::now();

  std::cout << "Time taken by quick sort = " <<
      std::chrono::duration_cast<std::chrono::microseconds>
      (end - begin).count() << " microseconds" <<std::endl;

  //  Why random is slower?
  //  because the gen random ?
  begin = std::chrono::high_resolution_clock::now();
  quick_sort_random<int>(S2->begin(), S2->end());
  end = std::chrono::high_resolution_clock::now();

  std::cout << "Time taken by quick sort random = " <<
      std::chrono::duration_cast<std::chrono::microseconds>
      (end - begin).count() << " microseconds" <<std::endl;
}
