#include "ForwardList.hpp"

int main()
{
    stl::ForwardList<int> f;
    for (size_t i = 0; i < 10; ++i)
        f.Push(rand() % 256);

    stl::ForwardList<int> b = { 5, 1, 2, 5 };
    b                       = f;

    std::cout << b << std::endl;
    std::cout << b.Size() << std::endl;

    b.Erase(b.end());

    std::cout << b << std::endl;
    return 0;
}
