/****************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers       */
/*                                                                                                  */ 
/* Warnings: This code demonstrate using corresponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                              */                  
/* Author:   Oleksii Reshta	                                                                        */
/****************************************************************************************************/

#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::string;


const string sInfo =
/*****************************************************************************************************/
	" Book:       Effective Modern C++. The first edition.                     			            \n"
	" Item: #33.  Example 1. Use decltype on auto&& parameters to std::forward them                 \n"
	" Code type:  good.                                               			 	              \n\n" 
/****************************************************************************************************/
;


double pwr( double d, unsigned int n )
{
    if( n == 0 )
    {
        return 1;
    }
    
    double mult = d;
    for( int i = 1; i <n; i++)
    {
        mult *= d;
    }

    return mult;
}

double pwr( double d, double n )
{
    return pow( d, n );
}

int32_t main()
{
	cout << sInfo << endl;
    
    auto f =
        [](auto&&... param)
        {
            return
            pwr(std::forward<decltype(param)>(param)...);
        };

    cout << "2^10 = " << f(2.0, 10u) << endl;
    cout << "sqrt(9) = " << f(9.0, 0.5) << endl;

	return 0;
} 
