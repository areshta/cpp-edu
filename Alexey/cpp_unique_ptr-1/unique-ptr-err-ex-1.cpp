//
// How a smart pointer to convert to a crazy pointer
//
#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

int32_t main()
{
	const int bsz = 100;
	char *pStrange = nullptr;
	{
		unique_ptr<char> pStr1( new char[bsz] );
		pStrange = pStr1.get(); 
		strncpy(pStrange, "String #1", bsz);
	
		cout << pStrange << endl; // "String #1"
	}

	unique_ptr<char> pStr2( new char[bsz] );
	strncpy(pStr2.get(), "String #2", bsz);

	cout << pStrange << endl; // Ops! We did nothing with pStrange but output is "String #2"!
}
