#include "ForwardList.hpp"

int main()
{
    stl::ForwardList<int> f{ 10, 23, 50, 12, 5 };

    // stl::ForwardList<int> b; // = { 5, 1, 2, 5 };
    // b = f;

    std::cout << f << std::endl;
    std::cout << f.Size() << std::endl;

    f.Reverse();

    std::cout << f << std::endl;
    return 0;
}
