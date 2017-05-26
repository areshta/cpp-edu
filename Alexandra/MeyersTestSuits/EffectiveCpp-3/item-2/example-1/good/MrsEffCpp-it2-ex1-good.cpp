/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate usein correpondent item. Please ignore other possible warnings. */
/*           c++11 standard is assumed                                                             */                  
/***************************************************************************************************/

//Book:      Effective C++. Third edition
//Item: #2.  Prefer const s, enum s, and inline s to #define s.
//Code type: good

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

template<typename T>
inline int DubleMax(const T& a, const T& b)
{
	return 2*( a>b? (a):(b));
}

const int32_t someValue = 3;

const string someString( "Some string" );

class SomeClass
{
private:
	static const int someValue = 3;
	int mSomeArray[someValue];
};

int32_t main()
{
	cout << "Effective C++. Third edition. Item 2. Good code" << endl;
    cout << "Some string: " << someString << endl;
    cout << "Some value: " << someValue << endl;
	int32_t a = 1;
	int32_t b = 2;
	cout << "Duble Max of 1 , 2 with pre-incremental of 2: " << DubleMax( a, ++b ) << endl;
}
