#include "ForwardList.hpp"

int main()
{
    stl::ForwardList<int> f;
    for (size_t i = 0; i < 10; ++i)
        f.Push(rand() % 256);

    stl::ForwardList<int> b = { 5, 1, 2, 5 };
    b                       = f;

    for (auto e : b)
    {
        std::cout << e << " ";
    }
    return 0;
}
