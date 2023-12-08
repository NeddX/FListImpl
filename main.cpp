#include "ForwardList.hpp"

int main()
{
    stl::ForwardList<int> f{ 10, 23, 50, 12, 5 };

    std::cout << f << std::endl;
    f.Insert(f.end(), 0);
    f.Insert(f.begin(), 0);
    std::cout << f << std::endl;
    return 0;
}
