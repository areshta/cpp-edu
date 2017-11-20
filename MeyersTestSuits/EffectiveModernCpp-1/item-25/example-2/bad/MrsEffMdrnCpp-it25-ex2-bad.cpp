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

const string sInfo =
/*******************************************************************************************************/
	" Book:       Effective Modern C++. The first edition.                     			                \n"
	" Item: #25.  Example 2. Use std::move on rvalue references, std::forward on universal references   \n"
	" Code type:  bad.                                               			 	                    \n\n" 
/*******************************************************************************************************/
;


template<typename T>
void Loger1( T&& sInfo )
{
	T sLocal = sInfo;
	cout << "Loger 1:" << sLocal << endl;
} 


template<typename T>
void Loger2( T&& sInfo )
{
	T sLocal = sInfo;
	cout << "Loger 2:" << sLocal << endl;
} 

template<typename T>
void doubleLog( T&& sInfo )
{
	Loger1( std::forward<T>(sInfo) ); // Bad: use forvard for the latest using only
	Loger2( std::forward<T>(sInfo) ); 
}


string getSomeInfo()
{
	string sInfo = 	"someInfo";
	return sInfo;
}

int32_t main()
{
	cout << sInfo << endl;

	doubleLog( getSomeInfo() );
	
	return 0;
} 
