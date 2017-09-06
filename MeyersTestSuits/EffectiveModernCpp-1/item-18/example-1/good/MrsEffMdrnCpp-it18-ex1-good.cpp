/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate using correponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                             */                  
/***************************************************************************************************/

#include <iostream>
#include <string>
#include <memory>
#include <list>
#include <vector>

using namespace std;

const string sInfo =
/*****************************************************************************************************/
	" Book:       Effective Modern C++. The first edition.                     			        \n"
	" Item: #18.  Example 1. Use std::unique_ptr for exclusive-ownership resource management    \n"
	" Code type:  good.                                             			 	          \n\n" 
/****************************************************************************************************/
;

template <typename Base, typename Child, typename Param>
unique_ptr<Base> FactoryCreater(const initializer_list<Param>& plist) // OK: using unique_ptr
{
	return unique_ptr<Base>( new Child(plist) ); 
}	

class Base
{
public:
	virtual void someOut() = 0;
};

class Child1: public Base
{
public:
	Child1(const initializer_list<string>& pList)
	{
		if( pList.begin() != pList.end() )
		{
			mString1 = *(pList.begin());
		}
	}
    virtual void someOut() override
	{
		cout << "Some output:" << mString1 << endl;
	}
private:
	string mString1 = "String1 child1 default.";
};

class Child2: public Base
{
public:
	Child2(const initializer_list<string>& pList)
	{
		mStrings.insert( mStrings.end(), pList.begin(), pList.end() );
	}
    virtual void someOut() override
	{
		cout << "Some words from Child2:" << endl;
		for( auto& s: mStrings)
		{
			cout << " | " << s;
		}
		cout << " |" << endl;
	}
private:
	vector<string> mStrings;
};


int32_t main()
{
	cout << sInfo << endl;
	vector< unique_ptr<Base> > v; // OK: using unique_ptr

	v.push_back( FactoryCreater<Base,Child1,string>( {"Child1 message."} ) );
	v.push_back( FactoryCreater<Base,Child1,string>( {} ) );
	v.push_back( FactoryCreater<Base,Child2,string>( {"one","two","thee"} ) );
	v.push_back( FactoryCreater<Base,Child2,string>( {"one"} ) );
	v.push_back( FactoryCreater<Base,Child2,string>( {} ) );

	for( auto& c: v)
	{
		c->someOut();
	}
		
	return 0;
} //OK: using dinamyc memory withou 'delete' operator and memory leaks. 	
