#pragma once
// MIT License
// Copyright 2023--present Rohit Goswami <HaoZeke>
#include "fmt/core.h"
#include "fmt/format.h"
#include "xtensor/xarray.hpp"
#include "xtensor/xview.hpp"

namespace fmt {

template <typename E, class S, class... FS>
struct formatter<xt::xview<E, S, FS...>> {
  template <typename ParseContext> constexpr auto parse(ParseContext &ctx) {
    return ctx.begin();
  }

  template <typename FormatContext>
  auto format(const xt::xview<E, S, FS...> &view, FormatContext &ctx) {
    auto out = ctx.out();

    // Handle 1D array
    if (view.dimension() == 1) {
      out = fmt::format_to(out, "[");
      for (std::size_t i = 0; i < view.shape()[0]; ++i) {
        if (i > 0)
          out = fmt::format_to(out, ", ");
        out = fmt::format_to(out, "{}", view(i));
      }
      out = fmt::format_to(out, "]");
    }
    // Handle 2D array
    else if (view.dimension() == 2) {
      out = fmt::format_to(out, "[");
      for (std::size_t i = 0; i < view.shape()[0]; ++i) {
        if (i > 0)
          out = fmt::format_to(out, ",\n ");
        out = fmt::format_to(out, "[");
        for (std::size_t j = 0; j < view.shape()[1]; ++j) {
          if (j > 0)
            out = fmt::format_to(out, ", ");
          out = fmt::format_to(out, "{}", view(i, j));
        }
        out = fmt::format_to(out, "]");
      }
      out = fmt::format_to(out, "]");
    } else {
      out = fmt::format_to(out, "Only 1D and 2D arrays are supported.");
    }
    return out;
  }
};

} // namespace fmt
