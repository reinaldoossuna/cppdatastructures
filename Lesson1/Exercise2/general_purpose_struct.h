#pragma once

#include <array>
#include <type_traits>
#include <utility>

template<typename ... Args>
auto build_array(Args&& ... args) -> std::array<typename
                                               std::common_type<Args ...>::type, sizeof ...(args)> {
  using commonType = typename std::common_type<Args...>::type;
  return {std::forward<commonType>(args)...};
}
