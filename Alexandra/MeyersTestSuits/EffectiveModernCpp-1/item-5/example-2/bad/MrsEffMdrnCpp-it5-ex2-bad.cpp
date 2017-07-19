/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate using correponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                             */                  
/***************************************************************************************************/

//Book:      Effective Modern C++. The first edition.
//Item: #5.  Prefer auto to explicit type declarations.
//Code type: bad

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class MyString: public string
{
public:
    using string::string ;
	string& getString(){ return *(static_cast<string *>(this)); }
	~MyString () { cout << "destructor: " << *(static_cast<string *>(this)) << endl; } 
};

class hashing_func {
    public:
        unsigned long operator()(const MyString& key) const {
            unsigned long hash;
            hash = std::hash<string>( *(static_cast<const string *>(&key)) );
            return hash;
        }
};

class key_equal_fn {
    public:
        bool operator()(const MyString& t1, const MyString& t2) const {
            return (t1 == t2);
        }
};


int32_t main()
{
	cout << "Effective Modern C++. The first edition. Item 5. Bad code." << endl;

/*	unordered_map<MyString,int> someMap;


	MyString s1 { string("One") };
	MyString s2 { string("Two") };

	someMap[s1] = 1;
	someMap[s2] = 2;*/

	unordered_map<MyString, int, hashing_func, key_equal_fn> someMap;
	MyString s {"aaa"};
	someMap[s] = 5;


	return 0;

}
