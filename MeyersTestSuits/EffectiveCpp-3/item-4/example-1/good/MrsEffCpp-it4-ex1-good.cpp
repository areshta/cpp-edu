/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate usein correpondent item. Please ignore other possible warnings. */
/*           c++11 standard is assumed                                                             */                  
/***************************************************************************************************/

//Book:      Effective C++. Third edition
//Item: #4.  Make sure that objects are initialized.
//Code type: good

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;

class ABEntry 
{
public:
	ABEntry(const string& name, const string& address, const string& phones):
		theName(name),
		theAddress(address),
		thePhones(phones),
		numTimesConsulted(0)
	{}

private:
	string theName;
	string theAddress;
	string thePhones;
	int numTimesConsulted;
};

struct NewStruct
{
	int a = 100;
	int b = 200;
};

class BadSiquence
{
public:
	BadSiquence(int a, int b, int c);
	int mC;
	int mA;
	int mB;
};
BadSiquence::BadSiquence(int a, int b, int c):
	mC(c),
	mA(a),
	mB(b)
	
{}

int main()
{
	cout << "Effective C++. Third edition. Item 4. Bad code" << endl;
	int a = 0;
	cout << "Initialized integer = " << a << endl;
	ABEntry abe("abe", "qwe", "0123654");
	NewStruct newStruct;
	cout << "Initialized struct members: " << newStruct.a << '\t' << newStruct.b << endl; 
	const char *pSomeString = "Some string";
	cout << "Initialized string: " << pSomeString << endl;
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	cout << "Initialized array's member = " << arr[5] << endl;
	BadSiquence bS(0, 1, 2);
}
