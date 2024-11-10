#pragma once

#include <Colors.hpp>
#include <iostream>
#include <random>
#include <ranges>
#include <vector>

inline auto render_rainbow(std::vector<Colors> enabled_colours,
                           std::size_t count) {
  std::cout << "LOOK: \n";
  std::random_device r;
  std::default_random_engine e1(r());
  std::uniform_int_distribution<int> uniform_dist(0,
                                                  enabled_colours.size() - 1);
  for ([[maybe_unused]] auto _unused : std::views::iota(0ul, count)) {
    std::cout << enabled_colours[uniform_dist(e1)];
  }
  std::cout << '\n';
}
