#pragma once

#include <ostream>
enum class Colours { white, red, green, blue, black };

inline std::ostream &operator<<(std::ostream &os, Colours c) {
  switch (c) {
  case Colours::white:
    return os << "\x1b[47m \x1b[0m";
  case Colours::red:
    return os << "\x1b[41m \x1b[0m";
  case Colours::green:
    return os << "\x1b[42m \x1b[0m";
  case Colours::blue:
    return os << "\x1b[44m \x1b[0m";
  case Colours::black:
    return os << "\x1b[40m \x1b[0m";
  };
  return os;
}
