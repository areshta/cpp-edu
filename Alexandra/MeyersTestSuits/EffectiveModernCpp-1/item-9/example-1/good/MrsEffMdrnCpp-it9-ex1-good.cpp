/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate using correponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                             */                  
/***************************************************************************************************/

//Book:      Effective Modern C++. The first edition.
//Item: #9.  Exampe 1. Prefer alias declarations to typedef's
//Code type: good

#include <iostream>
#include <string>
#include <memory>

using namespace std;

using  SomeSize = int; // OK

using SF = void (*) (int, const string&); // OK

void SomeFun(int someInt, const string& s)
{
	cout << s << " " << someInt << endl;
}

int32_t main()
{
	// function alias example
	cout << "Effective Modern C++. The first edition. Item 9. Example 1: Prefer alias declarations to typedef's. Good code." << endl;

	SF sf = SomeFun;
	SomeSize ss = 5;
	sf(ss, "Some out");

	return 0;
}
