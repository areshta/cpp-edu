#include <iostream>
#include <array>

using namespace std;

enum En
{
	a, b, c, d
};

template<typename T, En ... args>
class en_array: public array<T,sizeof...(args)>
{
};

class A
{
	public:
	en_array<int,a,b,c,d> ar;	
};

int main()
{
	A a;
	cout << a.ar.size() << endl;
	for( int i=0; i<4; ++i)
		cout << a.ar[i] << endl;
}

