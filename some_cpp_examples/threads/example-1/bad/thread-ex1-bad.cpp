/****************************************************************************************************/
/* Some cpp examples																		        */
/*                                                                                                  */ 
/* Warnings: This code demonstrate using corresponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                              */                  
/* Copypaster:)   Oleksii Reshta	                                                                */
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
	" Source:     http://www.bogotobogo.com/cplusplus/multithreaded4_cplusplus11.php 	            \n"
	" C++ items   threads												                            \n"
	" Example 1.  Catching local memory of finished thread                                          \n"
	"             Please use '-pthread' g++ parameter.                                              \n"
	" Code type:  bad.                                               			 	              \n\n" 
/****************************************************************************************************/
;

#include <iostream>
#include <thread>

using namespace std;

void foo(int i) { cout << "foo() i = " << i << endl; }

struct task_struct
{
	int& i;

	task_struct(int& ii):i(ii){ 
		cout << "task_struct constructor i = " << i << endl;
	}

	void operator()()
	{
		for(unsigned j = 0; j < static_cast<unsigned>(-1) >> 1 ; ++j)
		{
			cout << j << ": foo()\n";
			foo(i);
		}
	}
};

void A_function_creating_a_thread_within()
{
	int state = 99;
	task_struct task(state);

	cout << "Launching a thread\n";
	std::thread t(task);

	cout << "detaching the thread\n";
        // do not wait for the thread to finish
	t.detach();
}

int32_t main()
{
	cout << sInfo << endl;

	A_function_creating_a_thread_within();

	foo(2222); // to change the stack condition

	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	cout << "END OF PROGRAM\n";
	return 0;
} 
