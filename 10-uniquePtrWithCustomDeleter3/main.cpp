// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <cassert>
#include <cstdio>
#include <memory>

namespace details {
    template<auto DeleteFn>
    struct UniquePtrDeleter
    {
        template<class T>
        void operator()(T* ptr) const
        {
            assert(0 == DeleteFn(ptr));
        }
    };
}  // namespace details

template<typename T, auto DeleteFn>
using unique_ptr_deleter =
    std::unique_ptr<T, details::UniquePtrDeleter<DeleteFn>>;

template<typename T, auto DeleteFn, class... Args>
auto make_unique_deleter(Args&&... args)
{
    return unique_ptr_deleter<T, DeleteFn>{
        new T(std::forward<Args>(args)...)};
}

class MyClass
{
private:
    ~MyClass() = default;

public:
    MyClass(int) {}
    void Destroy() {}
};

void Destroy(MyClass* p)
{
    p->Destroy();
}

int main()
{
    auto p = make_unique_deleter<MyClass, Destroy>(2);
}