#include <ArgParser.hpp>
#include <ranges>
#include <string_view>
#ifdef TEST_FEATURES_ENABLED
#include <iostream>
#endif

auto ArgParser::parse(int argc, const char **argv) -> bool {
  if (argc < 2 || (argc - 2) >= (to_int(Colors::black) + 2))
    return false;
  std::vector<std::string_view> args(
      argv, std::next(argv, static_cast<std::ptrdiff_t>(argc)));

  // for (auto &&[i, arg] : std::views::enumerate(args)) {
  int i = 0;
  for (auto arg : args) {
    if (i == 0) {
      i++;
      continue;
    }

    if (i == 1) {
      _number = std::stoul(std::string(arg));
      i++;
      continue;
    }

    _colors.push_back(Colors(std::stoul(std::string(arg))));
    i++;
  }

  if (_colors.size() == 0) {
    for (auto &&colour_num :
         std::views::iota(to_int(Colors::white), to_int(Colors::black))) {
      _colors.push_back(Colors(colour_num));
    }
  }

  return true;
}

#ifdef TEST_FEATURES_ENABLED
void ArgParser::help() {
  std::cout << "Usage: ./example [count] [[colour] ...]\n";
}
#endif
