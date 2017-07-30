/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate using correponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                             */                  
/***************************************************************************************************/

//Book:      Effective Modern C++. The first edition.
//Item: #8.  Exampe 1. Prefer nullptr to 0 and NULL
//Code type: bad

#include <iostream>
#include <vector>

using namespace std;

void someOldFun(const char* const pS)
{
	static uint32_t counter = 0;

	if( pS != NULL) // bad: nullptr must be used
	{
		cout << pS << endl;
	}
	else
	{
		cout << "Null pointer detected: "<< static_cast<const void* const>(pS) << endl;		
	}
}

int32_t main()
{
	cout << "Effective Modern C++. The first edition. Item 8. Example 1: Prefer nullptr to 0 and NULL. Good code." << endl;

	someOldFun("Normal string");
	someOldFun( 0 ); 		// bad: nullptr must be used
	someOldFun( NULL );		// bad: nullptr must be used
	
	return 0;
}
