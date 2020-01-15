#pragma once

#include <vector>
#include <iostream>

enum class city : int
{
    LONDON,
    MOSCOW,
    ISTANBUL,
    DUBAI,
    MUMBAI,
    SEATTLE,
    SINGAPORE
};

std::ostream& operator <<(std::ostream& os, const city c) {
    switch(c)
    {
        case city::LONDON:
            os << "LONDON";
            return os;
        case city::MOSCOW:
            os << "MOSCOW";
            return os;
        case city::ISTANBUL:
            os << "ISTANBUL";
            return os;
        case city::DUBAI:
            os << "DUBAI";
            return os;
        case city::MUMBAI:
            os << "MUMBAI";
            return os;
        case city::SEATTLE:
            os << "SEATTLE";
            return os;
        case city::SINGAPORE:
            os << "SINGAPORE";
            return os;
        default:
            return os;
    }
}

struct graph {
  std::vector<std::vector<int>> data;

  graph(int n) {
      data.reserve(n);
      std::vector<int> row(n);
      std::fill(row.begin(), row.end(), -1);
      for (int i = 0; i < n ; i++) {
      data.push_back(row);
      }
  }

  void add_edge(const city c1, const city c2, int dist) {
    std::cout << "ADD: " << c1 << "-" << c2 << "=" << dist << std::endl;
    auto n1 = static_cast<int>(c1);
    auto n2 = static_cast<int>(c2);
    data[n1][n2] = dist;
    data[n2][n1] = dist;
  }
  void remove_edge(const city c1, const city c2) {
    std::cout << "RM " << c1 << "-" << c2 << std::endl;
    auto n1 = static_cast<int>(c1);
    auto n2 = static_cast<int>(c2);
    data[n1][n2] = -1;
    data[n2][n1] = -1;
  }
};
