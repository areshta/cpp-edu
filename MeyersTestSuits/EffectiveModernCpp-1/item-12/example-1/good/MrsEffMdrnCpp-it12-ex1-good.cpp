/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate using correponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                             */                  
/***************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

const string sInfo =
/**********************************************************************************/
	" Book:       Effective Modern C++. The first edition.          \n"
	" Item: #12.  Example 1. Declare overriding functions override. \n"
	" Code type:  good.                                              \n\n" ;
/**********************************************************************************/

class Base
{
public:
	virtual void Voice() 
	{  
		cout << "It is class Base" << endl;
	}
};

class Child1: public Base
{
public:
	void Voice() override // OK
	{  
		cout << "It is class Child1" << endl;
	}
};

class Child2: public Base
{
public:
	void Voice() override // OK
	{  
		cout << "It is class Child2" << endl;
	}
};


int32_t main()
{
	cout << sInfo << endl;

	vector< unique_ptr<Base> > vec;
	
    vec.push_back( move( unique_ptr<Base> (new Base) ));
	vec.push_back( move( unique_ptr<Base> (new Child1 )));
	vec.push_back( move( unique_ptr<Base> (new Child2 )));

	for(auto& p: vec)
	{
		p->Voice();
	}

	return 0;
}
