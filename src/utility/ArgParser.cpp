#include <ArgParser.hpp>
#include <ranges>
#include <string_view>
#ifdef TEST_FEATURES_ENABLED
#include <iostream>
#endif

bool ArgParser::parse(int argc, const char **argv) {
  if (argc < 2 || (argc - 2) >= (static_cast<int>(Colours::black) + 2))
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

    _colours.push_back(static_cast<Colours>(std::stoul(std::string(arg))));
    i++;
  }

  if (_colours.size() == 0) {
    for (auto &&colour_num :
         std::views::iota(static_cast<int>(Colours::white), 5)) {
      _colours.push_back(static_cast<Colours>(colour_num));
    }
  }

  return true;
}

std::size_t ArgParser::get_count() { return _number; }

#ifdef TEST_FEATURES_ENABLED
void ArgParser::help() {
  std::cout << "Usage: ./example [count] [[colour] ...]\n";
}
#endif

std::vector<Colours> ArgParser::get_colours() { return _colours; }
