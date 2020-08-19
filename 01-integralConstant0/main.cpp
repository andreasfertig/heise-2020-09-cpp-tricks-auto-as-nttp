// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdio>
#include <memory>

constexpr std::integral_constant<decltype(10), 10> c1;
constexpr std::integral_constant<bool, true>       c2;
constexpr std::integral_constant<int, 'a'>         c3;

int main(){}