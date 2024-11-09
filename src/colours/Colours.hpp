#pragma once

#include <ostream>
enum class Colours { white, red, green, blue, black };

inline std::ostream &operator<<(std::ostream &os, Colours c) {
  switch (c) {
  case Colours::white:
    return os << "\033[0;97m \033[0m";
  case Colours::red:
    return os << "\033[0;91m \033[0m";
  case Colours::green:
    return os << "\033[0;92m \033[0m";
  case Colours::blue:
    return os << "\033[0;94m \033[0m";
  case Colours::black:
    return os << "\033[0;90m \033[0m";
  };
  return os;
}
