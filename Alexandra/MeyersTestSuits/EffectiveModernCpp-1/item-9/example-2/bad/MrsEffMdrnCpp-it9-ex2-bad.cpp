/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate using correponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                             */                  
/***************************************************************************************************/

//Book:      Effective Modern C++. The first edition.
//Item: #9.  Exampe 2. Prefer alias declarations to typedefs
//Code type: bad

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template<typename T>
class MyAllocator: public allocator<T>
{
public:
	using allocator<T>::allocator;
	~MyAllocator()
	{
		cout << "My allocator destructor" << endl;
	}
};


template<typename T>
struct MyAllocVector
{
	typedef vector<T, MyAllocator<T> > type; // bad: 'using' is better!
};


int32_t main()
{
	cout << "Effective Modern C++. The first edition. Item 9. Exampe 2. Prefer alias declarations to typedefs. Bad code." << endl;
	MyAllocator<int> my_a; //verifying customizing allocator class
	
	MyAllocVector<int>::type my_v(2); //Interesting: without size presetting the allocator is not called.
	my_v[0]=10;
	my_v[1]=-999;

	for( auto i: my_v)
	{
		cout << i << endl;
	}

	return 0;
}
