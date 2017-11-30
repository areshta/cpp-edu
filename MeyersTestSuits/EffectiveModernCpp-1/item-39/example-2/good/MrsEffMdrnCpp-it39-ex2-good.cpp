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
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::condition_variable;
using std::mutex;
using std::unique_lock;
using std::vector;
using std::thread;
using std::promise;
using namespace std::this_thread;
using namespace std::chrono;


const string sInfo =
/*****************************************************************************************************/
	" Book:       Effective Modern C++. The first edition.                     			            \n"
	" Item: #39.  Example 1. Consider void futures for one-shot event communication	                \n"
	"             Please use '-pthread' g++ parameter.                                              \n"
	" Code type:  good.                                               			 	              \n\n" 
/****************************************************************************************************/
;

struct SomeShare
{
	int m_var1 = 1;
	int m_var2 = 2;
};

SomeShare 		gShare;
promise<void> 	gPromis;

void someAsyncFun(int nThread)
{
	cout << "someAsyncFun " << nThread <<": gShare.m_var1 = " << gShare.m_var1 << endl;
	cout << "someAsyncFun " << nThread <<": gShare.m_var2 = " << gShare.m_var2 << endl;
}

int32_t main()
{
	const size_t nThreads = 10;

	cout << sInfo << endl;

	auto sf = gPromis.get_future().share();
	
	vector<thread> vt;
	for (int i = 0; i < nThreads ; ++i) 
	{
		vt.emplace_back(
			[sf,i]
			{ 
				sf.wait(); 		
				someAsyncFun(i); 
			}
		); 
	} 
	
	sleep_for(200ms);

	gShare.m_var1 = 11;	
	gShare.m_var2 = 22;	
	cout << "main: data ready" << endl;

	gPromis.set_value();

	for (auto& t : vt) 
	{ 
		t.join(); 
	}	

	cout << "main: exit" << endl;

	return 0;
} 
