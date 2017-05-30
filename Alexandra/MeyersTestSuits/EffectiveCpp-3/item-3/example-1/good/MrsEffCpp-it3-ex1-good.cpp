/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate usein correpondent item. Please ignore other possible warnings. */
/*           c++11 standard is assumed                                                             */                  
/***************************************************************************************************/

//Book:      Effective C++. Third edition
//Item: #3.  Use const wherenever possible.
//Code type: good

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class TextBlock {
public:
	TextBlock(const string& someText):
		mSomeText(someText)
	{}

	const char& operator[](std::size_t position) const
	{
		return mSomeText[position];
	}
	char& operator[](std::size_t position)
	{
		return const_cast<char&>
		(
			static_cast<const TextBlock&>(*this)[position]
		);
	}
	

private:
	string mSomeText;
	const int mSomeValue = 1;
	const static mSomeStaticValue = 2;
};


int main()
{
	cout << "Effective C++. Third edition. Item 3. Bad code" << endl;

    TextBlock tb("Hello");	//calls non-const operator[]
	cout << tb[0] << endl;

	const TextBlock ctb("World");	//calls const operator[]
	cout << ctb[0] << endl;

	const char * greeting = "Hello";
	const char * const p = greeting; 	//const * at const char

	vector<int> vec = {1, 2, 3, 4, 5};
	const vector<int>::iterator iter =	vec.begin();	//iterator isn’t allowed to point to something different
	cout << *iter << '\t';
	*iter = 10;
	cout << *iter << '\t';
	*iter = 15;
	cout << *iter << endl;
	
	vector<int>::const_iterator cIter =	vec.begin();	//points to something that can’t be modified
	++cIter;
	
}

