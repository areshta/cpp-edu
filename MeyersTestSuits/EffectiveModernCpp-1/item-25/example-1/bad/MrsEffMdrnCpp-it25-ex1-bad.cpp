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
	" Item: #25.  Example 1. Use std::move on rvalue references, std::forward on universal references   \n"
	" Code type:  bad.                                               			 	                    \n\n" 
/*******************************************************************************************************/
;


class SomeClass
{
public:
	template<typename T>
	void setName( T&& sName)
	{
		m_sName = move(sName); // Very Bad!
	}
private:
	string m_sName;
	//other data...
};

string nameFabric()
{
	return "Some Name";
}

int32_t main()
{
	cout << sInfo << endl;

	string sName = nameFabric();
	cout << "Name before: " << sName << endl;
	SomeClass sc;
	sc.setName(sName); // Very bad: moving data from local variable
	cout << "Name after: " << sName << endl; //Do you need such behavior of sName?
	
	return 0;
} 
