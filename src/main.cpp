#include <ArgParser.hpp>
#include <Rainbow.hpp>

std::random_device dev;
std::default_random_engine engine(dev());

auto random_colors() -> decltype(auto) {
  std::uniform_int_distribution<int> color_dist(to_int(Colors::white),
                                                to_int(Colors::black));
  std::vector<Colors> out;
  for ([[maybe_unused]] auto i : std::views::iota(0, color_dist(engine) + 1)) {
    auto color = Colors(color_dist(engine));
    if (std::ranges::find(out, color) != out.end()) {
      continue;
    }
    out.push_back(color);
  }
  return out;
}

auto random_count() -> decltype(auto) {
  std::uniform_int_distribution<std::uint16_t> size_t_dist(1);
  return size_t_dist(engine);
}

int main(int argc, const char **argv) {
  auto argparser = ArgParser{};

  if (argparser.parse(argc, argv)) {
    render_rainbow(argparser.get_colors(), argparser.get_count());
  } else {
    auto colors = random_colors();
    render_rainbow(std::span{colors}, random_count());
#ifdef UT_ARGS_HAVE_TEST_FEATURES
    argparser.help();
#endif
  }

  return 0;
}
