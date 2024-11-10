#include <Colors.hpp>
#include <cstddef>
#include <vector>

class ArgParser {
public:
  bool parse(int, const char **);
#ifdef UT_ARGS_HAVE_TEST_FEATURES
  void help();
#endif
  std::vector<Colors> get_colours();
  std::size_t get_count();

private:
  std::vector<Colors> _colours = {};
  std::size_t _number = 0;
};
