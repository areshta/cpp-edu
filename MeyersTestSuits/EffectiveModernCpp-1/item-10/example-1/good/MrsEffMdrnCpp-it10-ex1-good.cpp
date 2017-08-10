/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate using correponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                             */                  
/***************************************************************************************************/

//Book:      Effective Modern C++. The first edition.
//Item: #10.  Example 1. Prefer scoped enums to unscoped enums
//Code type: good

#include <iostream>
#include <string>
#include <memory>

using namespace std;

int32_t main()
{
	cout << "Effective Modern C++. The first edition. Item 10. Example 1. Prefer scoped enums to unscoped enums. Good code." << endl;

	enum class SomeEnum { cat, dog, caw }; // OK

/*
	crazy code is not compiled
	if ( dog < 1.77 ) //comparing dog with double!
	{
		cout << "Crazy code working" << endl;
	} 
*/

	if ( static_cast<double>(SomeEnum::dog) < 1.77 ) //comparing dog with double!
	{
		cout << "Still crazy but such code difficult write by mistake. Probably there was some snse)" << endl;
	} 


	return 0;
}
