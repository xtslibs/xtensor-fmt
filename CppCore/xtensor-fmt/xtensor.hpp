#pragma once
// MIT License
// Copyright 2023--present Rohit Goswami <HaoZeke>
#include "fmt/core.h"
#include "fmt/format.h"
#include "xtensor/xtensor.hpp"

namespace fmt {

template <typename T, std::size_t N> struct formatter<xt::xtensor<T, N>> {
  // Parse format specifiers if needed. Empty for demonstration.
  template <typename ParseContext> constexpr auto parse(ParseContext &ctx) {
    return ctx.begin();
  }

  // Format the xtensor object and append it to the output.
  template <typename FormatContext>
  auto format(const xt::xtensor<T, N> &arr, FormatContext &ctx) {
    auto out = ctx.out();
    // Handle 1D array
    if constexpr (N == 1) {
      out = fmt::format_to(out, "[");
      for (std::size_t i = 0; i < arr.size(); ++i) {
        if (i > 0)
          out = fmt::format_to(out, ", ");
        out = fmt::format_to(out, "{}", arr[i]);
      }
      out = fmt::format_to(out, "]");
    }
    // Handle 2D array
    else if constexpr (N == 2) {
      out = fmt::format_to(out, "[");
      for (std::size_t i = 0; i < arr.shape()[0]; ++i) {
        if (i > 0)
          out = fmt::format_to(out, ",\n ");
        out = fmt::format_to(out, "[");
        for (std::size_t j = 0; j < arr.shape()[1]; ++j) {
          if (j > 0)
            out = fmt::format_to(out, ", ");
          out = fmt::format_to(out, "{}", arr(i, j));
        }
        out = fmt::format_to(out, "]");
      }
      out = fmt::format_to(out, "]");
    }
    // Unsupported dimensions
    else {
      out = fmt::format_to(out, "Only 1D and 2D arrays are supported.");
    }
    return out;
  }
};
} // namespace fmt
