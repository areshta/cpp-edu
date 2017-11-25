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
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;

const string sInfo =
/*****************************************************************************************************/
	" Book:       Effective Modern C++. The first edition.                     			            \n"
	" Item: #31.  Example 1. Avoid default capture modes.                                           \n"
	" Code type:  good.                                               			 	              \n\n" 
/****************************************************************************************************/
;

using VS = vector<string>;

void mySort(VS& someStrings)
{
    bool bySize =  true;
    std::sort(someStrings.begin(), someStrings.end(),
          [bySize] (const auto& a, auto& b) // OK: variable was sent by value 
                { 
                    if( bySize )
                    {
                         return a.size() < b.size(); 
                    }
                    else
                    {
                         return a < b; 
                    }
                }
            );
}


int32_t main()
{
	cout << sInfo << endl;
    
    VS someStrings = {"a","aa","aaa","b","bb","bbb"};

    mySort(someStrings);
	
    for(auto& i : someStrings )
    {
        cout << i << endl;
    }

	return 0;
} 
