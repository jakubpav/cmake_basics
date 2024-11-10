#pragma once

#include <ostream>
enum class Colors { white, red, green, blue, black };

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
