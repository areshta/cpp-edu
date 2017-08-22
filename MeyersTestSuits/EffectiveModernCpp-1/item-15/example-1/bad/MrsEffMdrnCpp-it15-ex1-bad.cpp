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
	" Item: #15.  Example 1. Use constexpr whenever possible.                           \n"
	" Code type:  bad.                                             					  \n\n" 
/*********************************************************************************************/
;

using tmpr = double;

tmpr CtoF(tmpr celsius) //bad. constexpr must be used
{
	return (celsius * 9.0) / 5.0 + 32.0;
}

int32_t main()
{
	cout << sInfo << endl;
	
	tmpr someTemperature =  100;

	cout << "fahrenheit of zero celsius = " << CtoF(0.0) << endl;  // bad run-time using. build-time may be used instead
	cout << "fahrenheit of " << someTemperature << " celsius = " << CtoF(someTemperature) << endl; // run-time using
	return 0;
}
