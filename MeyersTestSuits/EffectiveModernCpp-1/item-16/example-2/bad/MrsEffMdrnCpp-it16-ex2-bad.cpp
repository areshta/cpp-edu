/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate using correponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                             */                  
/***************************************************************************************************/

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <atomic>

using namespace std;

const string sInfo =
/*********************************************************************************************/
	" Book:       Effective Modern C++. The first edition.          					\n"
	" Item: #16.  Example 2. Make const member functions thread safe.                           \n"
	" Code type:  good.                                             					  \n\n" 
/*********************************************************************************************/
;

const size_t duration = 10;

class SomeObjectWithCash
{

public:
	int longCalculate(int inValue) const
	{
		int res {0}; 

		//emulation of some long calculation
		for(size_t i=0; i < abs(inValue); ++i)
		{		
			res += i*5;	
			this_thread::sleep_for(chrono::milliseconds(20));
		}
		return res;
	}

	int getResults(int inValue) const
	{		
		if( inValue == mOldIntValue )
		{
			cout << "cash is used" << endl;
			return mSomeIntRes;
		}
		else
		{
			auto val1 = longCalculate(inValue);
			auto val2 = longCalculate(inValue*2);
			mSomeIntRes = val1 + val2;
			mOldIntValue = inValue;
			cout << "new values are calculated" << endl;
			return mSomeIntRes;
		}
	}
private:
	mutable atomic<int> mOldIntValue{-1};	//using atomic twice is bad. t is working but not effective
	mutable atomic<int> mSomeIntRes {0};	//
};

SomeObjectWithCash sOWC;

template<int ID>
void secondary() 
{
	
	for(size_t i = 0; i < duration; ++i) 
	{
		cout << "therad " << ID << ": " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(50));
		
		cout << "Some value:" << sOWC.getResults( 10*(1+rand()%2) ) <<endl; // calling of global object with long operation
	}
}

int32_t main()
{
	cout << sInfo << endl;

	thread t1 = thread(secondary<1>);
	thread t2 = thread(secondary<2>);
	
	t1.join();
	t2.join();
	return 0;
}
