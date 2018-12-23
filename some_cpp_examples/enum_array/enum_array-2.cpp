#include <iostream>
#include <array>

using namespace std;

enum En
{
	a1, a2, a3, a4, a5, a6, a7
};

template<typename... Args>
constexpr int argsCount(Args... args)
{
	return sizeof...(Args);
}

constexpr int arSz = argsCount(a1, a2, a3, a4, a5, a6, a7);
static_assert(arSz - a7 - 1 == 0);

/*
constexpr int theLast(int a)
{
	return a;
}

template<typename... A1, typename... A2>
constexpr int theLast(A1... ar, A2 ...br)
{
	return theLast(br...);
}
*/


int main()
{
	//cout << "theLast" << theLast(a1, a2, a3, a4, a5, a6, a7) << endl;	
	
	std::array<int, arSz> ar;
	cout << arSz << endl;

	for(auto& i: ar)
	{
		i = 7;
	}
	cout << ar.size() << endl;
	for( auto i: ar)
		cout << i << endl;
}

