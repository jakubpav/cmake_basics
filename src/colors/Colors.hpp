#pragma once

#include <ostream>
#include <ranges>

enum class Colors { white, red, green, blue, black };

template <typename R>
concept color_view =
    std::ranges::view<R> &&
    std::same_as<std::remove_cvref_t<std::ranges::range_value_t<R>>, Colors>;

inline std::ostream &operator<<(std::ostream &os, Colors c) {
  switch (c) {
  case Colors::white:
    return os << "\x1b[47m \x1b[0m";
  case Colors::red:
    return os << "\x1b[41m \x1b[0m";
  case Colors::green:
    return os << "\x1b[42m \x1b[0m";
  case Colors::blue:
    return os << "\x1b[44m \x1b[0m";
  case Colors::black:
    return os << "\x1b[40m \x1b[0m";
  };
  return os;
}

constexpr auto to_int(Colors &&c) -> decltype(auto) {
  switch (c) {
  case Colors::white:
    return 0;
  case Colors::red:
    return 1;
  case Colors::green:
    return 2;
  case Colors::blue:
    return 3;
  case Colors::black:
    return 4;
  }
}
