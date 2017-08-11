/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate using correponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                             */                  
/***************************************************************************************************/

//Book:      Effective Modern C++. The first edition.
//Item: #10.  Example 2. Prefer scoped enums to unscoped enums
//Code type: bad

#include <iostream>
#include <string>
#include <tuple>

using namespace std;

using SomePersona = tuple<string, int>;

enum {PersonaName, PersonaAge}; // bad: convinient but rusty. Better to use scoped enum


SomePersona getPersona()
{
	return tuple<string, int>(string("John"),25) ;
}

int32_t main()
{
	cout << "Effective Modern C++. The first edition. Item 10. Example 2. Prefer scoped enums to unscoped enums. Bad code." << endl;

	SomePersona sp = getPersona();
	cout << get<PersonaName>(sp) << " " << get<PersonaAge>(sp) << endl;

	return 0;
}
