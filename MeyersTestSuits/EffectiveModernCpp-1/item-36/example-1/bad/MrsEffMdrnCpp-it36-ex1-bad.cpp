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
	" Item: #36.  Example 1. Specify std::launch::async ifasynchronicity is essential.              \n"
	"             Please use '-pthread' g++ parameter.                                              \n"
	" Code type:  bad.                                               			 	              \n\n" 
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

    auto fut1 = std::async(asyncF1);  //Bad: it could be sync or async implementation
    auto fut2 = std::async(asyncF2);  

    while (fut1.wait_for(100ms) != std::future_status::ready) 
    { 
        cout << "The application can hang. Press ^C to break executing." << endl;
    }
	
    cout << "fut1 = " << fut1.get() << endl;
    cout << "fut2 = " << fut2.get() << endl;
    cout << "Exit" << endl;

	return 0;
} 
