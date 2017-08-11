/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate using correponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                             */                  
/***************************************************************************************************/

//Book:      Effective Modern C++. The first edition.
//Item: #10.  Example 2. Prefer scoped enums to unscoped enums
//Code type: good

#include <iostream>
#include <string>
#include <tuple>

using namespace std;

template<typename E>
constexpr typename underlying_type<E>::type
toUType(E enumerator) noexcept
{
	return static_cast<typename underlying_type<E>::type>(enumerator);
}

using SomePersona = tuple<string, int>;

enum class PersonaData {PersonaName, PersonaAge}; // good: scoped enum (but little more code is needed)


SomePersona getPersona()
{
	return tuple<string, int>(string("John"),25) ;
}

int32_t main()
{
	cout << "Effective Modern C++. The first edition. Item 10. Example 2. Prefer scoped enums to unscoped enums. Good code." << endl;

	SomePersona sp = getPersona();
	cout << get<toUType(PersonaData::PersonaName)>(sp) << " " << get<toUType(PersonaData::PersonaAge)>(sp) << endl;

	return 0;
}
