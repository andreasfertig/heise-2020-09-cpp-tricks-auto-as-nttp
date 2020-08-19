// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdio>
#include <memory>

#if 0
int main()
{
    auto p = std::unique_ptr<FILE, decltype([](FILE* f) { fclose(f); })>{
        fopen("SomeFile.txt", "r")};
}

#else
#ifdef _MSC_VER
#pragma message("Not supported yet")
#else
#warning("Not supported yet")
#endif
int main(){}
#endif