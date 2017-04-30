// Demonstration the difference between c++98 and c++11 (By Oleksii Reshta)
// Old c++ will return the vector by value
// C++11/14/17 will use move operation
// As result address of the vector buffer will be the same in main() and f()
// so, there will not coping of vector data, but owner vector will be changed

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;

VI f()
{
	VI v;
	for(int i=0; i < 100; i++)
	{
		v.push_back(i);
	} 
	cout <<"vector adr: " << &v << "    " << "vector buffer adr" << v.data() << endl;
	return v;
}


int main()
{
	VI v;
	v = f();
	cout <<"vector adr: " << &v << "    " << "vector buffer adr" << v.data() << endl;

	return 0;
}

/*
RUNNING SCRIPT:
clear
echo C++ moving operations demo
echo
echo C++ 98 output:
g++ -std=c++98 main.cpp -o main
./main
echo
echo C++ 11 output:
g++ -std=c++11 main.cpp -o main
./main
*/

/*
OUTPUT:
C++ moving operations demo

C++ 98 output:
vector adr: 0x7fff03ade4c0    vector buffer adr0x213ce80
vector adr: 0x7fff03ade4a0    vector buffer adr0x213cc20

C++ 11 output:
vector adr: 0x7ffefe43c5e0    vector buffer adr0x2081e80
vector adr: 0x7ffefe43c5c0    vector buffer adr0x2081e80
*/
