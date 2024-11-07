#include <ArgParser.hpp>
#include <Graphics.hpp>

int main(int argc, const char **argv) {
  auto argparser = ArgParser{};

  if (argparser.parse(argc, argv)) {
    render_rainbow(argparser.get_colours(), argparser.get_count());
  }
#ifdef ARGS_HAVE_TEST_FEATURES
  else {
    argparser.help();
  }
#endif

  return 0;
}
