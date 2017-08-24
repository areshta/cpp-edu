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
#include <vector>
#include <cassert>
#include <cstdlib>
#include <mutex>

using namespace std;

const string sInfo =
/*********************************************************************************************/
	" Book:       Effective Modern C++. The first edition.          					\n"
	" Item: #16.  Example 1. Make const member functions thread safe.                           \n"
	" Code type:  good.                                             					  \n\n" 
/*********************************************************************************************/
;

const size_t duration = 10;
using Results = vector<size_t>;

class SomeObjectWithCash
{

public:
	const void longCalculate(int inValue)	
	{
		this_thread::sleep_for(chrono::milliseconds(100));
		mvResults.clear();
		this_thread::sleep_for(chrono::milliseconds(100));
		//emulation of some long calculation
		for(size_t i=0; i < abs(inValue); ++i)
		{			
			mvResults.push_back(i*5);
			this_thread::sleep_for(chrono::milliseconds(20));
		}
	}
	const Results getResults(int inValue)
	{		
		// bad. Mhe program will be creshed by assert. Mutex guard must be here: lock_guard<mutex> g(m);
		if( inValue == mOldIntValue )
		{
			//additional validation: is all OK during muti-threading access.
			assert( abs(inValue) ==  mvResults.size() );
			cout << "cash is used" << endl;
			return mvResults;
		}
		else
		{
			longCalculate(inValue);
			mOldIntValue = inValue;
			cout << "new values are calculated" << endl;
			return mvResults;
		}
	}
private:
	mutable mutex m;
	mutable int mOldIntValue;	
	mutable Results mvResults {}; 
};

SomeObjectWithCash sOWC;

void Output(const Results& vr)
{
	cout << "Some results" << " ";
	for (auto i: vr)
	{
		cout << i << " " ;
	}
	cout << endl;
}



template<int ID>
void secondary() 
{
	
	for(size_t i = 0; i < duration; ++i) 
	{
		cout << "therad " << ID << ": " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(50));
		
		Output( sOWC.getResults( 10*(1+rand()%2) ) ); // calling of global object with long operation
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
