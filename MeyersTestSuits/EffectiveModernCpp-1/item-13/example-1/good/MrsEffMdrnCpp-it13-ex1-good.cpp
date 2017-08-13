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
	" Code type:  good.                                             \n\n" ;
/**********************************************************************************/

template<typename C, typename V>
void findAndInsert(C& container, const V& targetVal, const V& insertVal)
{
	auto it = find(cbegin(container), cend(container), targetVal); // C++14, global cbegin and cend are present
	container.insert(it, insertVal);
}

int32_t main()
{
	cout << sInfo << endl;

	vector<int> someVector {0,1,2,3,4,6,7,8,9};
	
	vector<int>::const_iterator it = find(someVector.begin(),someVector.end(), 6); //OK
	someVector.insert(it, 5);

	auto it2 = find(someVector.cbegin(),someVector.cend(), 0); //OK, as cbegin, cend are const ittertors
	someVector.insert(it2, -1);

	findAndInsert(someVector, -1, -2); // OK for C++14

	for( auto i: someVector)
	{
		cout << i << " ";
	} 

	cout << endl;

	return 0;
}
