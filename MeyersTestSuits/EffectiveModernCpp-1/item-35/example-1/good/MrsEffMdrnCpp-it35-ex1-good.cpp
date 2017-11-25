/****************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers       */
/*                                                                                                  */ 
/* Warnings: This code demonstrate using corresponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                              */                  
/* Author:   Oleksii Reshta	                                                                        */
/****************************************************************************************************/

#include <iostream>
#include <string>
#include <future>
#include <chrono>

using std::cout;
using std::endl;
using std::string;
using std::async;
using namespace std::chrono;
using namespace std::this_thread;


const string sInfo =
/*****************************************************************************************************/
	" Book:       Effective Modern C++. The first edition.                     			            \n"
	" Item: #35.  Example 1. Prefer task-based programming to threadbased.                          \n"
	"             Please use '-pthread' g++ parameter.                                              \n"
	" Code type:  good.                                               			 	              \n\n" 
/****************************************************************************************************/
;

int asyncF1()
{
    for( int i=0; i<10; ++i)
    {
        cout << "asyncF1" << endl;
        sleep_for(nanoseconds(100000));
    }
    return 1;
}

int asyncF2()
{
    for( int i=0; i<10; ++i)
    {
        cout << "   asyncF2" << endl;
        sleep_for(nanoseconds(100000));
    }
    return 2;
}

int32_t main()
{
	cout << sInfo << endl;

    auto fut1 = std::async(std::launch::async, asyncF1); // Good: using std::async instead thread 
    auto fut2 = std::async(std::launch::async, asyncF2); // Good: using std::async instead thread 
	
    cout << "fut1 = " << fut1.get() << endl;
    cout << "fut2 = " << fut2.get() << endl;
    cout << "Exit" << endl;

	return 0;
} 
