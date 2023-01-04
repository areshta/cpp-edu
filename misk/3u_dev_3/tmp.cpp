#include <iostream>

int main()
{
    std::cout << -3/3u*3 << std::endl;
    std::cout << static_cast<int>(-3/3u*3) << std::endl;    
    std::cout << static_cast<unsigned int>(-1) << std::endl;

    std::cout << "-3/3u*3 = " << int(-3/3u*3) << "\n";
}
