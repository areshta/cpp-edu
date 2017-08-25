/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate using correponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                             */                  
/***************************************************************************************************/

#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

const string sInfo =
/*********************************************************************************************/
	" Book:       Effective Modern C++. The first edition.                     			\n"
	" Item: #17.  Example 1. The special member functions generation issue.             \n"
	" Code type:  good.                                             			 	  \n\n" 
/*********************************************************************************************/
;


class SomeStringTable
{
public:
	SomeStringTable()
	{
		string s;
		for(int i=0; i<10; i++)
		{
			s = "String #" + to_string(i);
			//cout << s << endl;
			mTable[i] = s;
		}
		for( auto i: mTable)
		{
			cout << i.second << endl;
		} 
	}

private:
	map<int, string> mTable;
};

int32_t main()
{
	cout << sInfo << endl;

	SomeStringTable sTable;
		
	return 0;
}
