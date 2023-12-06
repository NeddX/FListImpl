#include "ForwardList.hpp"

int main()
{
    stl::ForwardList<int> f;
    for (size_t i = 0; i < 2; ++i)
        f.Push(rand() % 256);

    // stl::ForwardList<int> b; // = { 5, 1, 2, 5 };
    // b = f;

    std::cout << f << std::endl;
    std::cout << f.Size() << std::endl;

    f.Erase(f.begin(), f.end() - 1);

    std::cout << f << std::endl;
    return 0;
}
