#include <iostream>
#include <array>

using namespace std;

template<typename T, typename... Args>
class A
{
public:
   static array<T,5> mArray;
};

template<typename T, typename... Args> array<T,5> A<T, Args...>::mArray;


int main(int argc, char** argv) {

   return 0;
}

