#pragma once
// MIT License
// Copyright 2023--present Rohit Goswami <HaoZeke>

// clang-format off
#include <string>
#include "xtensor-fmt/xarray.hpp"
#include "xtensor-fmt/xview.hpp"
// clang-format on

namespace xtfmt {

template <typename T>
void pxt(const xt::xarray<T> sinp, std::string name = "var") {
  fmt::print("Shape of {}: {}\n", name, fmt::join(sinp.shape(), ", "));
  fmt::print("Number of dimensions of {}: {}\n", name, sinp.dimension());
  if (sinp.dimension() == 1 || sinp.dimension() == 2 || sinp.dimension() == 0) {
    fmt::print("{} is:\n{}\n", name, sinp);
  } else {
    fmt::print("Only 1D and 2D arrays are supported for direct print.\n");
  }
}

template <typename T>
void pxt(const xt::xview<T> sinp, std::string name = "var") {
  fmt::print("Shape of {}: {}\n", name, fmt::join(sinp.shape(), ", "));
  fmt::print("Number of dimensions of {}: {}\n", name, sinp.dimension());
  if (sinp.dimension() == 1 || sinp.dimension() == 2 || sinp.dimension() == 0) {
    fmt::print("{} is:\n{}\n", name, sinp);
  } else {
    fmt::print("Only 1D and 2D arrays are supported for direct print.\n");
  }
}

} // namespace xtfmt
