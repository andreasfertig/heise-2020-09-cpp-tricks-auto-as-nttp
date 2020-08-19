// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <array>
#include <cstdio>

template<typename T, size_t N1, size_t N2>
constexpr auto join(std::array<T, N1>& a, std::array<T, N2>& b)
{
    std::array<T, N1 + N2> ret{};

    auto copy = [&, i = 0](const auto& ar) mutable {
        for(const auto& e : ar) {
            ret[i] = e;
            ++i;
        }
    };

    copy(a);
    copy(b);

    return ret;
}

int main()
{
    std::array<char, 2> a{'h', 'e'};
    std::array          b{'l', 'l', 'o'};

    auto ab = join(a, b);

    for(const auto e : ab) {
        printf("%c\n", e);
    }
}