/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate usein correpondent item. Please ignore other possible warnings. */
/*           c++11 standard is assumed                                                             */                  
/***************************************************************************************************/

//Book:      Effective C++. Third edition
//Item: #2.  Prefer const s, enum s, and inline s to #define s.
//Code type: bad

#include <iostream>

using std::cout;
using std::endl;

#define MACRO_FUN_DUBLE_MAX( a, b ) 2*( a>b? (a):(b) )
//Prefer: inline int DubleMax( int a, int b ) { return 2*( a>b? (a):(b); }    
//        or template solution.

#define SOME_VALUE 3
//Prefer: const int32_t someValue = 3;

#define SOME_STRING "Some string"
//Prefer: const string someString( "Some string" );

class SomeClass
{
private:
	int mSomeArray[SOME_VALUE];
	// Prefer: using static const member as number of elements
};

int32_t main()
{
	cout << "Effective C++. Third edition. Item 2. Bad code" << endl;
    cout << "Some string: " << SOME_STRING << endl;
    cout << "Some value: " << SOME_VALUE << endl;
	int32_t a = 1;
	int32_t b = 2;
	cout << "Duble Max of 1 , 2 with pre-incremental of 2: " << MACRO_FUN_DUBLE_MAX( a, ++b ) ;
    cout << ".    Wairing = 6, have = 8"  << endl;  
}
