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
	" Code type:  good.                                               			 	              \n\n" 
/****************************************************************************************************/
;


int32_t main()
{
	cout << sInfo << endl;

	vector<string> vs;
	
	vs.emplace_back("To be, or not to be, that is the question!"); // OK. emplace_back can is used instead

	cout << "Some string: " << vs[0] << endl;

	vector<regex> regexes;
	
	regexes.emplace_back("(\\S+)"); // Ok

	 
    auto words_begin = 
        std::sregex_iterator(vs[0].begin(), vs[0].end(), regexes[0]);
    auto words_end = std::sregex_iterator();
 
    std::cout << "Found "
              << std::distance(words_begin, words_end)
              << " words\n";

	cout << "main: exit" << endl;
	
	return 0;
} 
