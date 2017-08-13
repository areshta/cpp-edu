/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate using correponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                             */                  
/***************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

const string sInfo =
/**********************************************************************************/
	" Book:       Effective Modern C++. The first edition.          \n"
	" Item: #13.  Example 1. Prefer const_iterators to iterators.   \n"
	" Code type:  bad.                                              \n\n" ;
/**********************************************************************************/



int32_t main()
{
	cout << sInfo << endl;

	vector<int> someVector {0,1,2,3,4,6,7,8,9};
	
	vector<int>::iterator it = find(someVector.begin(),someVector.end(), 6); //bad: must be constant iterrator
	someVector.insert(it, 5);

	for( auto i: someVector)
	{
		cout << i << " ";
	} 

	cout << endl;

	return 0;
}
