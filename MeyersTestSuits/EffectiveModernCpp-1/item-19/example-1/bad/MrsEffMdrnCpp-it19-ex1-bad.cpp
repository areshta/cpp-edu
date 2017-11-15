/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate using correponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                             */                  
/***************************************************************************************************/

#include <iostream>
#include <string>
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;

const string sInfo =
/*****************************************************************************************************/
	" Book:       Effective Modern C++. The first edition.                     			            \n"
	" Item: #19.  Example 1. Use std::shared_ptr for shared-ownership resource management    	    \n"
	" Code type:  bad.                                               			 	               \n\n" 
/****************************************************************************************************/
;

class SomeClass
{
    public:
    SomeClass()
    {
        cout << " SomeClass constrctor" << endl;
    }
    ~SomeClass()
    {
        cout << " SomeClass destructor" << endl;
    }

};


int32_t main()
{
	cout << sInfo << endl;

    auto pSome = new SomeClass;
    
    auto logDel = [](SomeClass *p)
    {
        cout << "log of del" << endl;
        delete p;
    };

    shared_ptr<SomeClass> sp1(pSome, logDel); // Bad: using raw pointer for initialising of shared_ptr
    shared_ptr<SomeClass> sp2(pSome, logDel); // Error: Creating of new control block for the same pointer!
		
	return 0;
} // Double removing of the same pointer!
