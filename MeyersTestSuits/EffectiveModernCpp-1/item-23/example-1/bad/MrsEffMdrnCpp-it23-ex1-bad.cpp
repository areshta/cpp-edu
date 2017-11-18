/****************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers       */
/*                                                                                                  */ 
/* Warnings: This code demonstrate using corresponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                              */                  
/* Author:   Oleksii Reshta	                                                                        */
/****************************************************************************************************/

#include <iostream>
#include <string>
#include <utility>

using std::cout;
using std::endl;
using std::string;
using std::move;

class MyString: public string
{
public:
    using string::string ;
    MyString( MyString&& ms): string(ms) { cout << "MyString Move constructor" << endl; }
    MyString( const MyString& ms): string(ms) { cout << "MyString copy constructor" << endl; }
};

MyString moveDemo()
{
    MyString ms {"moveDemo function"};
    return ms; // Bad: operation withot move
}


const string sInfo =
/*****************************************************************************************************/
	" Book:       Effective Modern C++. The first edition.                     			            \n"
	" Item: #23.  Example 1. Understand std::move and std::forward                                  \n"
	" Code type:  bad.                                               			 	              \n\n" 
/****************************************************************************************************/
;


int32_t main()
{
	cout << sInfo << endl;

    MyString ms { moveDemo() };
    cout << "Get from function: " << static_cast<string>( ms ) << endl;

	return 0;
} 
