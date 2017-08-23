/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate using correponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                             */                  
/***************************************************************************************************/

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

const string sInfo =
/*********************************************************************************************/
	" Book:       Effective Modern C++. The first edition.          					\n"
	" Item: #16.  Example 1. Make const member functions thread safe.                           \n"
	" Code type:  good.                                             					  \n\n" 
/*********************************************************************************************/
;

int32_t main()
{
	cout << sInfo << endl;

	for(size_t i = 0; i < 3*60; ++i) 
	{
		cout << "therad 1: " << i << endl;
		this_thread::sleep_for(chrono::seconds(1));
	}
	return 0;
}
