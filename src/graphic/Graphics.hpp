#pragma once

#include <Colours.hpp>
#include <iostream>
#include <random>
#include <ranges>
#include <vector>

auto render_rainbow(std::vector<Colours> enabled_colours, std::size_t count) {
  std::random_device r;
  std::default_random_engine e1(r());
  std::uniform_int_distribution<int> uniform_dist(
      static_cast<int>(Colours::white), static_cast<int>(Colours::black));
  for (auto i : std::views::iota(count)) {
    std::cout << static_cast<Colours>(i);
  }
  std::cout << '\n';
}
