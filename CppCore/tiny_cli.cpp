// MIT License
// Copyright 2023--present Rohit Goswami <HaoZeke>
#include <fmt/format.h>
#include <fmt/ostream.h>

#include <cmath>
#include <cstdlib>

#include <iostream>
#include <random>

#include "xtensor-fmt/xarray.hpp"

int main(int argc, char *argv[]) {
  // Eat warnings, also safer
  static_cast<void>(argc);
  static_cast<void>(argv);
  xt::xarray<double> x = xt::arange<double>(0, 10, 1);
  fmt::print("x = {}\n", x);
  return EXIT_SUCCESS;
}
