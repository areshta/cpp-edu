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
#include <thread>

using std::cout;
using std::endl;
using std::string;
using std::condition_variable;
using std::mutex;
using std::unique_lock;
using namespace std::this_thread;
using namespace std::chrono;


const string sInfo =
/*****************************************************************************************************/
	" Book:       Effective Modern C++. The first edition.                     			            \n"
	" Item: #39.  Example 1. Consider void futures for one-shot event communication	                \n"
	"             Please use '-pthread' g++ parameter.                                              \n"
	" Code type:  bad.                                               			 	              \n\n" 
/****************************************************************************************************/
;

struct SomeShare
{
	int m_var1 = 1;
	int m_var2 = 2;
};

SomeShare gShare;

condition_variable 	gCv;
mutex				gMutex; 

template<typename F, typename... Ts>
inline auto reallyAsync( F&& f, Ts&&... params )
{
    return std::async(  std::launch::async,
                        std::forward<F>(f),
                        std::forward<Ts>(params)...);
}

void someAsyncFun()
{
	cout << "someAsyncFun: start" << endl;
	

	unique_lock<std::mutex> lk(gMutex); 
	cout << "someAsyncFun: data waiting" << endl;
	gCv.wait(lk); //Bad. Additiona guard is needed to privent spurious wakeups.

	cout << "someAsyncFun: gShare.m_var1 = " << gShare.m_var1 << endl;
	cout << "someAsyncFun: gShare.m_var2 = " << gShare.m_var2 << endl;

	cout << "someAsyncFun: exit" << endl;
}

int32_t main()
{
	cout << sInfo << endl;
	
	auto Ret = reallyAsync(someAsyncFun);
	
	sleep_for(100ms);

	gShare.m_var1 = 11;	
	gShare.m_var2 = 22;	
	
	gCv.notify_one();

	cout << "main: data ready" << endl;
	
	return 0;
} 
