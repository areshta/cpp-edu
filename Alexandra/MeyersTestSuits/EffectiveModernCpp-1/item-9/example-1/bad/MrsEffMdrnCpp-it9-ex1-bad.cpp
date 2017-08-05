/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate using correponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                             */                  
/***************************************************************************************************/

//Book:      Effective Modern C++. The first edition.
//Item: #9.  Exampe 1. Prefer alias declarations to typedef's
//Code type: bad

#include <iostream>
#include <string>
#include <memory>

using namespace std;

template <class T>
struct MyAllocator: public allocator<T>
{
	using allocator<T>::allocator;
	~MyAllocator()
	{
		cout << "My allocator is destroid!" << endl;
    }
};


typedef void (*SF)(int, const string&);

void SomeFun(int someInt, const string& s)
{
	cout << s << " " << someInt << endl;
}

int32_t main()
{
	// fuction alias example
	cout << "Effective Modern C++. The first edition. Item 9. Example 1: Prefer alias declarations to typedef's. Bad code." << endl;

	SF sf = SomeFun;
	sf(5, "Some out");

	// allocator example
	MyAllocator<int> a;

	return 0;
}
