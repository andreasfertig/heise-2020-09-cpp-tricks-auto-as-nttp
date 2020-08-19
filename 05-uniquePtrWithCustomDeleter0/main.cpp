// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdio>
#include <memory>

int main()
{
    auto p = std::unique_ptr<FILE, decltype(&fclose)>{
        fopen("SomeFile.txt", "r"), &fclose};
}