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
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::move;

const string sInfo =
/*****************************************************************************************************/
	" Book:       Effective Modern C++. The first edition.                     			            \n"
	" Item: #31.  Example 2. Avoid default capture modes.                                           \n"
	" Code type:  bad.                                               			 	              \n\n" 
/****************************************************************************************************/
;

using VS = vector<string>;

char *gpStr =  nullptr;

void mySort(VS& someStrings)
{
    bool bySize =  true;
    string sLocal = "Local";
    std::sort(someStrings.begin(), someStrings.end(),
          [&bySize,&sLocal] (const auto& a, auto& b) 
                { 
                    gpStr = const_cast<char*>(sLocal.c_str());  // Catastrofical! Assigning global pointer to local buffer
                                                                // in lambda function
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

    cout << "gpStr = " << gpStr << endl;

	return 0;
} 
