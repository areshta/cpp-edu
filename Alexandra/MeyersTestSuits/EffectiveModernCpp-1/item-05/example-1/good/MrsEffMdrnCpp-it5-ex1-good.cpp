/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate using correponding item. Please ignore other possible warnings. */
/*           c++11 standard is assumed                                                             */                  
/***************************************************************************************************/

//Book:      Effective Modern C++. The first edition.
//Item: #5.  Prefer auto to explicit type declarations.
//Code type: good

#include <iostream>
#include <vector>

using namespace std;

int32_t main()
{
	cout << "Effective Modern C++. The first edition. Item 5. Bad code." << endl;

	long int someValue = static_cast<unsigned>(-1) +1L;

	// danger! can be overfload: unsigned int badValue = someValue; 

	auto goodValue = someValue; // safely

	cout << "Good Value = " << goodValue << endl;

	return 0;

}
