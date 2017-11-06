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
	" Code type:  bad.                                             			 	        \n\n" 
/*********************************************************************************************/
;

// MyMap is created to show of using constructors
template<typename Key, typename Value>
class MyMap: public map<Key, Value>
{
public:
	MyMap():map<Key, Value>()
	{
		cout << "MyMap default constructor" << endl;
	}
	MyMap(const MyMap& m): map<Key, Value>(m)
	{
		cout << "MyMap coping constructor" << endl;
	}	
	MyMap(const MyMap&& m): map<Key, Value>(m)
	{
		cout << "MyMap moving constructor" << endl;
	}	
};


class SomeStringTable
{
public:
	SomeStringTable()
	{
		string s;
		for(int i=0; i<10; i++)
		{
			s = "String #" + to_string(i);
			mTable[i] = s;
		}
		for( auto i: mTable)
		{
			cout << i.second << endl;
		} 
	}
	~SomeStringTable(){}  // Bad. As destructor declared default copy constructor wll be use instead moving!

private:
	MyMap<int, string> mTable;
};

int32_t main()
{
	cout << sInfo << endl;

	SomeStringTable t1;
	auto t2 = move(t1); // Bad. Coping constructor will be used!
		
	return 0;
}
