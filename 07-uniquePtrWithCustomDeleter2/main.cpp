// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cstdio>
#include <memory>

namespace details {
    template<auto DeleteFn>
    struct UniquePtrDeleter
    {
        template<class T>
        void operator()(T* ptr) const
        {
            DeleteFn(ptr);
        }
    };
}  // namespace details

template<typename T, auto DeleteFn>
using unique_ptr_deleter =
    std::unique_ptr<T, details::UniquePtrDeleter<DeleteFn>>;

static_assert(sizeof(unique_ptr_deleter<FILE, fclose>{}) == sizeof(FILE*));

int main()
{
    auto p = unique_ptr_deleter<FILE, fclose>{fopen("SomeFile.txt", "r")};
}