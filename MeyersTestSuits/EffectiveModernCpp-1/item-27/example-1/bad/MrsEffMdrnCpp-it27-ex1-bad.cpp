/****************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers       */
/*                                                                                                  */ 
/* Warnings: This code demonstrate using corresponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                              */                  
/* Author:   Oleksii Reshta	                                                                        */
/****************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::move;
using std::forward;
using std::vector;

const string sInfo =
/*****************************************************************************************************/
	" Book:       Effective Modern C++. The first edition.                     			            \n"
	" Item: #27.  Example 1. Familiarize yourself with alternatives to                              \n"
    "                        overloading on universal references                                    \n"
	" Code type:  bad.                                               			 	              \n\n" 
/****************************************************************************************************/
;

const string& nameFromIdx(size_t nId)
{
	static vector<string> svData { "Non", "Ann", "Al", "Bill", "Kat", "Willy" };
	if( nId >= svData.size() )
	{
		nId = 0;
	}
	
	return svData[nId];
}

class SomeStr
{
public:
    template
    < 
        typename T,
        typename =  std::enable_if_t
                <
                    !std::is_base_of<SomeStr, std::decay_t<T>>::value // Bad: '!std::is_integral<std::remove_reference_t<T>>::value' is absent                                        
                >
    >
    explicit SomeStr(T&& str)
		: m_sStr (std::forward<T>(str))
	{
		static_assert(
			std::is_constructible<std::string, T>::value,
			"Error: constructor SomeClass(T&& n) cann't convert income parameter to a string"
		);	    
	}

	SomeStr( size_t nId):
		m_sStr( nameFromIdx(nId) )
	{
	}

	void out()
	{
		cout << "Some Str: " << m_sStr << endl;
 	}

private:
	string m_sStr;
};



int32_t main()
{
	cout << sInfo << endl;

	SomeStr s1("John"); 
	s1.out();
	SomeStr s2(string("Peppy")); 
	s2.out();
	SomeStr s3( static_cast<size_t>(1) ); // Bad. Situation with conversion can be fixed in 'SomeStr(T&& str)'
	s3.out(); 
	
	return 0;
} 
