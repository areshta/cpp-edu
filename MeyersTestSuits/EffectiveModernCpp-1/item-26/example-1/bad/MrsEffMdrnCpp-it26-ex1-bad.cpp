/****************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers       */
/*                                                                                                  */ 
/* Warnings: This code demonstrate using corresponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                              */                  
/* Author:   Oleksii Reshta	                                                                        */
/****************************************************************************************************/

#include <iostream>
#include <string>
#include <utility>
#include <set>
#include <chrono>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::move;
using std::multiset;
//using std::chrono;
using std::forward;
using std::vector;

const string sInfo =
/*****************************************************************************************************/
	" Book:       Effective Modern C++. The first edition.                     			            \n"
	" Item: #26.  Example 1. Avoid overloading on universal references.                             \n"
	" Code type:  bad.                                               			 	              \n\n" 
/****************************************************************************************************/
;


multiset<string> gSomeData;

using logtm = std::chrono::time_point<std::chrono::system_clock>; 

void log(const logtm& tm, const string& st)
{
	std::time_t now_c = std::chrono::system_clock::to_time_t(tm);
	cout << now_c << " : " << st << endl;
}

const string& nameFromIdx(size_t idx)
{
	static vector<string> svData { "Non", "Ann", "Al", "Bill", "Kat", "Willy" };
	if( idx >= svData.size() )
	{
		idx = 0;
	}
	
	return svData[idx];
}

template<typename T>
void logAndAdd(T&& sData)
{
	auto now = std::chrono::system_clock::now();
	log(now, sData);
	gSomeData.emplace(forward<T>(sData));
}

void logAndAdd(size_t idx) 
{
	auto now = std::chrono::system_clock::now();
	string sData = nameFromIdx(idx);
	log(now, sData);
	gSomeData.emplace(sData);
}

int32_t main()
{
	cout << sInfo << endl;

	string sName("John"); 
	logAndAdd(sName);
	logAndAdd(string("Peppy")); 
	logAndAdd("Abdula"); 
	logAndAdd(1); 	// Bad. Copiler error. "int" will be pass to "logAndAdd(T&& sData)".
					// static_cast<size_t>(1) can fix it.
	
	return 0;
} 
