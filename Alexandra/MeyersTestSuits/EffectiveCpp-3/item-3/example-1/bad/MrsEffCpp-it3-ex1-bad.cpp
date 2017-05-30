/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate usein correpondent item. Please ignore other possible warnings. */
/*           c++11 standard is assumed                                                             */                  
/***************************************************************************************************/

//Book:      Effective C++. Third edition
//Item: #3.  Use const wherenever possible.
//Code type: bad

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class TextBlock {
public:
	TextBlock(string& someText):
		mSomeText(someText)
	{}

	char& operator[](std::size_t position)
	{
		return mSomeText[position];
	}
	
private:
	string mSomeText;

};

void SomeOut (char* pSomeStr)	//pointer may be constant to constant string
{
	cout << pSomeStr << endl;
}

int32_t main()
{
	cout << "Effective C++. Third edition. Item 3. Bad code" << endl;
	
	string s = "Hello";
    TextBlock tb(s);
	cout << tb[0] << endl;
	const char* const pSomeString = "Some string";
	SomeOut( (char*) pSomeString );
}

