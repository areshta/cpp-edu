/****************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers       */
/*                                                                                                  */ 
/* Warnings: This code demonstrate using corresponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                              */                  
/* Author:   Oleksii Reshta	                                                                        */
/****************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <regex>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::regex;


const string sInfo =
/*****************************************************************************************************/
	" Book:       Effective Modern C++. The first edition.                     			            \n"
	" Item: #42.  Example 1. Consider emplacement instead of insertion.				                \n"
	" Code type:  bad.                                               			 	              \n\n" 
/****************************************************************************************************/
;


int32_t main()
{
	cout << sInfo << endl;

	vector<string> vs;
	
	vs.push_back("abc"); // Bad. emplace_back can be used instead

	cout << "Some string: " << vs[0] << endl;

	vector<regex> regexes;
	
	regexes.emplace_back("s/abc/bsd/g");

	regexes.emplace_back(nullptr); // Catastrofic!

	cout << "main: exit" << endl;
	
	return 0;
} 
