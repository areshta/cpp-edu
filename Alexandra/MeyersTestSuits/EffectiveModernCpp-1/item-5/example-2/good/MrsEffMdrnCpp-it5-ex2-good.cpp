/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate using correponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                             */                  
/***************************************************************************************************/

//Book:      Effective Modern C++. The first edition.
//Item: #5.  Prefer auto to explicit type declarations.
//Code type: good

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class MyString: public string
{
public:
    using string::string ;
	~MyString () { cout << "destructor: " << *this << endl; } 
};


class hashing_func {
    public:
        unsigned long operator()(const MyString& key) const 
		{
			hash<string> hash_fn;
			size_t hash = hash_fn(key);
            return hash;
        }
};

class key_equal_fn {
    public:
        bool operator()(const MyString& t1, const MyString& t2) const 
		{
			equal_to<string> eq_fn;
			return eq_fn (t1,t2);
        }
};


int32_t main()
{
	cout << "Effective Modern C++. The first edition. Item 5. Bad code." << endl;

	unordered_map<MyString, int32_t, hashing_func, key_equal_fn> someMap;
	MyString s1 {"one"};
	MyString s2 {"two"};
	someMap[s1] = 1;
	someMap[s2] = 2;
	
/*	using of wrong pair type cause creating additional temprorary object!
	for(const pair<MyString, int32_t>& p: someMap)
	{
		cout << p.second << endl;
	}*/

//  using auto is much better 	
	for(auto& p: someMap)
	{
		cout << p.second << endl;
	}

	return 0;

}
