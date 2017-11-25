/****************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers       */
/*                                                                                                  */ 
/* Warnings: This code demonstrate using corresponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                              */                  
/* Author:   Oleksii Reshta	                                                                        */
/****************************************************************************************************/

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


const string sInfo =
/*****************************************************************************************************/
	" Book:       Effective Modern C++. The first edition.                     			            \n"
	" Item: #34.  Example 1. Prefer lambdas to std::bind                                            \n"
	" Code type:  good.                                               			 	              \n\n" 
/****************************************************************************************************/
;

using Type1 = int;
using Type2 = int;
using Type3 = int;


void someViseFunction(Type1 p1, Type2 p2, Type3 p3 )
{
    cout    << "Vise function" << endl
            << "Parameter1 = " << p1 << endl      
            << "Parameter2 = " << p2 << endl      
            << "Parameter3 = " << p3 << endl;     
}


int32_t main()
{
	cout << sInfo << endl;

    cout << "Call #1" << endl; 
    someViseFunction( 1, 2, 3 );

    Type1 par1 = { 111 };
    Type2 par2 = { 000 };
    Type3 par3 = { 333 };
    
    auto useViseWith2 =
        [par1, par3]( auto&& par2 )
            {
                someViseFunction( par1, par2, par3 );
            };

    cout << "Call #2" << endl; 
    useViseWith2( 222 );
  
	return 0;
} 
