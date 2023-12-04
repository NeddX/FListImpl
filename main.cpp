#include "ForwardList.hpp"

int main()
{
    stl::ForwardList<int> f;
    for (size_t i = 0; i < 10; ++i)
        f.Push(rand() % 256);

    auto b = f;

    std::cout << b << std::endl;
    return 0;
}
