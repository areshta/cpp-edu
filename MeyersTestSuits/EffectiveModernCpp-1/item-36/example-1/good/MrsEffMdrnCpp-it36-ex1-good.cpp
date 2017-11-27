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
	" Code type:  good.                                               			 	              \n\n" 
/****************************************************************************************************/
;


template<typename F, typename... Ts>
inline auto reallyAsync( F&& f, Ts&&... params )
{
    return std::async(  std::launch::async,
                        std::forward<F>(f),
                        std::forward<Ts>(params)...);
}

int asyncF1()
{
    for( int i=0; i<10; ++i)
    {
        cout << "asyncF1" << endl;
        sleep_for(milliseconds(100));
    }
    return 1;
}

int asyncF2()
{
    for( int i=0; i<10; ++i)
    {
        cout << "   asyncF2" << endl;
        sleep_for(milliseconds(100));
    }
    return 2;
}

int32_t main()
{
	cout << sInfo << endl;

    auto fut1 = reallyAsync(asyncF1);  
    auto fut2 = reallyAsync(asyncF2);  
	
    cout << "fut1 = " << fut1.get() << endl;
    cout << "fut2 = " << fut2.get() << endl;
    cout << "Exit" << endl;

	return 0;
} 
