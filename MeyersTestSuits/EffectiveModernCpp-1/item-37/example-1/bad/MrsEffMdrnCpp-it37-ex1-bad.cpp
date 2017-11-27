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
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::string;
using std::thread;
using namespace std::chrono;
using namespace std::this_thread;


const string sInfo =
/*****************************************************************************************************/
	" Book:       Effective Modern C++. The first edition.                     			            \n"
	" Item: #37.  Example 1. Make std::threads unjoinable on all paths.				                \n"
	"             Please use '-pthread' g++ parameter.                                              \n"
	" Code type:  bad.                                               			 	              \n\n" 
/****************************************************************************************************/
;

void SomeVise()
{
    for( int i=0; i<10; ++i)
    {
        cout << "SomeVise: " << i << endl;
        sleep_for( milliseconds( 100 ) );
    }
}


void doSomthing()
{
	thread t(SomeVise);
	
    std::srand(unsigned(std::time(0)));
    int random_variable = std::rand();

	if ( random_variable % 2 )
	{
		t.join(); //Bad: not all path are unjoinable!
	}
	cout << "doSomthing end" << endl;
}

int32_t main()
{
	cout << sInfo << endl;
	
	doSomthing();

	cout << "Exit:" << endl;

	return 0;
} 
