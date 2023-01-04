#include <iostream>

using namespace std;


class A {};

class B: public A
{
    public:
    static constexpr const char* const shortName() {return "AB";};
};

int main()
{
    cout << B::shortName() << endl;

    return 0;
}
