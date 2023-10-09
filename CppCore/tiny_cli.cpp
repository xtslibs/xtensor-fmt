// MIT License
// Copyright 2023--present Rohit Goswami <HaoZeke>
#include <fmt/format.h>
#include <fmt/ostream.h>

#include <cmath>
#include <cstdlib>

#include <iostream>
#include <random>

#include "xtensor-fmt/xarray.hpp"
#include "xtensor-fmt/xview.hpp"

int main(int argc, char *argv[]) {
  // Eat warnings, also safer
  static_cast<void>(argc);
  static_cast<void>(argv);
  xt::xarray<double> x = xt::arange<double>(0, 10, 1);
  fmt::print("x = {}\n", x);

  // Views
  xt::xarray<double> arr2d = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  auto view1d = xt::view(arr2d, 1);
  auto view2d = xt::view(arr2d, xt::range(0, 3), xt::range(0, 3));
  fmt::print("1D View: {}\n", view1d);
  fmt::print("2D View: {}\n", view2d);

  return EXIT_SUCCESS;
}
