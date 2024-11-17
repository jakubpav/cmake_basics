#pragma once

#include <Colors.hpp>
#include <iostream>
#include <random>
#include <ranges>

template <typename Rng, typename T>
  requires std::integral<T> && color_view<Rng>
inline auto render_rainbow(Rng enabled_colors, T count) -> decltype(auto) {
  std::cout << "LOOK: "
#ifndef NDEBUG
            << (unsigned long long)(count) << ' '
            << std::ranges::size(enabled_colors)
#endif
            << '\n';
  if (std::ranges::size(enabled_colors) > 1) {
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(0,
                                                    enabled_colors.size() - 1);
    for ([[maybe_unused]] auto _unused : std::views::iota(0ul, count)) {
      std::cout << enabled_colors[uniform_dist(e1)];
    }
  } else if (std::ranges::size(enabled_colors) == 1) {
    for ([[maybe_unused]] auto _unused : std::views::iota(0ul, count)) {
      std::cout << enabled_colors[0];
    }
  }
  std::cout << '\n';
}
