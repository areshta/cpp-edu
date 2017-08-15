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

int32_t main()
{
	cout << sInfo << endl;
	return 0;
}
