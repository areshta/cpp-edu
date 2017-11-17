/****************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers       */
/*                                                                                                  */ 
/* Warnings: This code demonstrate using corresponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                              */                  
/* Author:   Oleksii Reshta	(аleх.rеshtа@gmаil.com - email is protected from bots, 					*/
/*                           please enter the address manualy, copy/past will not working)          */
/****************************************************************************************************/

#include <iostream>
#include <string>
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;

const string sInfo =
/*****************************************************************************************************/
	" Book:       Effective Modern C++. The first edition.                     			            \n"
	" Item: #21.  Example 1. Prefer std::make_unique and std::make_shared to direct use of new.	    \n"
	" Code type:  bad.                                               			 	              \n\n" 
/****************************************************************************************************/
;


class SomeClass
{
    public:
	void doSomething()
	{
		cout << "Did something" << endl;
	}
};



int32_t main()
{
	cout << sInfo << endl;	

	std::unique_ptr<SomeClass> up(new SomeClass); // Bad: without make func
	up->doSomething();

	std::shared_ptr<SomeClass> sp(new SomeClass); // Bad: without make func
	sp->doSomething();
	
	return 0;
} 
