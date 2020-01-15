#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

enum class city : int {
    LONDON,
    MOSCOW,
    ISTANBUL,
    DUBAI,
    MUMBAI,
    SEATTLE,
    SINGAPORE
};

std::ostream& operator <<(std::ostream& os, const city c) {
    switch (c) {
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
  std::vector<std::vector<std::pair<int, int>>> data;

  explicit graph(int n):data(std::vector<std::vector<std::pair<int, int>>>(n, std::vector<std::pair<int, int>>())) {}

  void add_edge(const city c1, const city c2, int dist) {
    std::cout << "ADD: " << c1 << "-" << c2 << "=" << dist << std::endl;
    auto n1 = static_cast<int>(c1);
    auto n2 = static_cast<int>(c2);
    data[n1].push_back({n2, dist});
    data[n2].push_back({n1, dist});
  }
  void remove_edge(const city c1, const city c2) {
    std::cout << "RM " << c1 << "-" << c2 << std::endl;
    auto n1 = static_cast<int>(c1);
    auto n2 = static_cast<int>(c2);
    std::remove_if(data[n1].begin(), data[n1].end(), \
                       [n2](const auto& pair) {
                         return pair.first == n2;
                       });
    std::remove_if(data[n2].begin(), data[n2].end(), \
                       [n1](const auto& pair) {
                         return pair.first == n1;
                       });
  }
};
