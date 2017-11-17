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

using std::cout;
using std::endl;
using std::string;

#include "SomeClass.h"


const string sInfo =
/*****************************************************************************************************/
	" Book:       Effective Modern C++. The first edition.                     			            \n"
	" Item: #22.  Example 1. When using the Pimpl Idiom, define special "
				  "member functions in the implementation file. 	    							\n"
	" Code type:  bad.                                               			 	              \n\n" 
/****************************************************************************************************/
;


int32_t main()
{
	cout << sInfo << endl;

	SomeClass s;	
	s.ouputData();

	return 0;
} 
