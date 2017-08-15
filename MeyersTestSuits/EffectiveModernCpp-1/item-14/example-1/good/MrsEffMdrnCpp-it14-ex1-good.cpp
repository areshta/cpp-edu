/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate using correponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                             */                  
/***************************************************************************************************/

#include <iostream>
#include <string>



using namespace std;

const string sInfo =
/*********************************************************************************************/
	" Book:       Effective Modern C++. The first edition.          					\n"
	" Item: #14.  Example 1. Declare functions noexcept if they won’t emit exceptions.  \n"
	" Code type:  good.                                             					\n\n" ;
/*********************************************************************************************/

class SomeSwapper
{
public:
	static void swap(int &a, int &b) noexcept // OK
	{
		a+=b;
		b=a-b;
		a=a-b;
	}	 
};

inline int DevByTwo(int a) noexcept // OK
{
	return a >> 1;
}


int32_t main()
{
	cout << sInfo << endl;

	int a = 2;
	int b = 1;
	SomeSwapper::swap(a,b);

	int c = DevByTwo(6);

	cout <<"a,b,c : "<< a <<","<< b <<","<< c <<"."<< endl;	

	return 0;
}
