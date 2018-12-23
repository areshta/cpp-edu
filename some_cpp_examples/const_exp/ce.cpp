#include <iostream>
#include <array>

using namespace std;

enum t1
{
	a, b, c, d
};

enum t2
{
	aa=10, bb=11, cc=12
};

constexpr static int sz = (d -a) +1;	

class a
{
	public:

	static_assert( sz == 4);
	array<int,sz> ar;

};

//int a::sz;

int main()
{
	cout << sz << endl;
	return 0;
}

