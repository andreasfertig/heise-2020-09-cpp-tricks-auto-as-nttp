// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdio>
#include <memory>

template<auto v>
using constant = std::integral_constant<decltype(v), v>;

constexpr constant<10>   c1;
constexpr constant<true> c2;
constexpr constant<'a'>  c3;

int main(){}