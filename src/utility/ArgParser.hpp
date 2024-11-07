#include <Colours.hpp>
#include <cstddef>
#include <vector>

class ArgParser {
public:
  bool parse(int, const char **);
#ifdef TEST_FEATURES_ENABLED
  void help();
#endif
  std::vector<Colours> get_colours();
  std::size_t get_count();
private:
  std::vector<Colours> _colours = {};
  std::size_t _number = 0;
};
