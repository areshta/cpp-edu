#include <iostream>

void crash()
{
    int *n;
    n[100]=5;
}

int main()
{
    std::cout << "ready to crash) \n";
    crash();
    return 0;
}
