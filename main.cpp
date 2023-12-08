#include "ForwardList.hpp"

int main()
{
    stl::ForwardList<int> f{ 10, 23, 50, 12, 5 };
    stl::ForwardList<int> g{ 0, 0, 0 };

    std::cout << f << std::endl;
    f.Insert(f.end(), g.begin(), g.end());
    std::cout << f << std::endl;
    return 0;
}
