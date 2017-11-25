/****************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers       */
/*                                                                                                  */ 
/* Warnings: This code demonstrate using corresponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                              */                  
/* Author:   Oleksii Reshta	                                                                        */
/****************************************************************************************************/

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using std::cout;
using std::endl;
using std::string;
using std::thread;
using namespace std::this_thread;
using namespace std::chrono;

const string sInfo =
/*****************************************************************************************************/
	" Book:       Effective Modern C++. The first edition.                     			            \n"
	" Item: #35.  Example 1. Prefer task-based programming to threadbased.                          \n"
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

    thread t1(asyncF1); //Bad: using thread instead std::async
    thread t2(asyncF2); //Bad: using thread instead std::async 

	t1.join();
    t2.join();

    cout << "Exit" << endl;

	return 0;
} 
