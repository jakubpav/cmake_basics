#include <Colors.hpp>
#include <cstddef>
#include <span>
#include <vector>

class ArgParser {
public:
  auto parse(int, const char **) -> bool;
#ifdef UT_ARGS_HAVE_TEST_FEATURES
  void help();
#endif
  constexpr auto get_colors() -> decltype(auto) { return std::span{_colors}; };
  constexpr auto get_count() -> std::size_t { return _number; };

private:
  std::vector<Colors> _colors = {};
  std::size_t _number = 0;
};
