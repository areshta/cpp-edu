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
using namespace std::chrono;
using namespace std::this_thread;


const string sInfo =
/*****************************************************************************************************/
	" Book:       Effective Modern C++. The first edition.                     			            \n"
	" Item: #37.  Example 1. Make std::threads unjoinable on all paths.				                \n"
	"             Please use '-pthread' g++ parameter.                                              \n"
	" Code type:  good.                                               			 	              \n\n" 
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

void SomeVise2()
{
    for( int i=0; i<10; ++i)
    {
        cout << "SomeVise2: " << i << endl;
        sleep_for( milliseconds( 50 ) );
    }
}


class ThreadRaii
{
public:
	enum class ExitMode { join, detach };

	ThreadRaii(thread t, ExitMode mode):
		m_Thread	{ std::move( t ) },
		m_Mode		{ mode }
	{}

	~ThreadRaii()
	{
		if ( m_Thread.joinable() )
		{
			switch ( m_Mode )
			{
				case ExitMode::join : 
					m_Thread.join(); 
					cout << "ThreadRaii was joind in the destuctor" << endl;
					break;
				case ExitMode::detach : 
					cout << "ThreadRaii was detached in the destuctor" << endl;
					m_Thread.detach(); 
					break;
			}
		}
	}

	ThreadRaii( ThreadRaii&& ) 			= default; 
	ThreadRaii& operator=(ThreadRaii&&) = default;
	
	// for do thomthing with native thread API	
	thread& get() 
	{ 
		return m_Thread; 
	} 
	
private:
	ExitMode	m_Mode;
	thread	 	m_Thread;
};


void doSomthing()
{
	ThreadRaii t( thread(SomeVise), ThreadRaii::ExitMode::join );
    //sleep_for( milliseconds( 300 ) );
	//thread t2(SomeVise2);
	//t2.join();
	cout << "doSomthing end" << endl;
}

int32_t main()
{
	cout << sInfo << endl;
	
	doSomthing();

	cout << "Exit:" << endl;

	return 0;
} 
