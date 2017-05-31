/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate usein correpondent item. Please ignore other possible warnings. */
/*           c++11 standard is assumed                                                             */                  
/***************************************************************************************************/

//Book:      Effective C++. Third edition
//Item: #4.  Make sure that objects are initialized.
//Code type: bad

#include <iostream>
#include <string>
#include <list>

using std::cout;
using std::endl;
using std::string;

class ABEntry 
{
public:
	ABEntry(const string& name, const string& address, const string& phones);
private:
	string theName;
	string theAddress;
	string thePhones;
	int numTimesConsulted;
};
ABEntry::ABEntry(const string& name, const string& address, const string& phones)
{
	theName = name;		//assignments, not initializations
	theAddress = address;
	thePhones = phones;
	numTimesConsulted = 0;
}

struct NewStruct
{
	int a;
	int b;
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
	mA(a),		//right siquences must be mC, mA, mB
	mB(b),
	mC(c)
{}

int main()
{
	cout << "Effective C++. Third edition. Item 4. Bad code" << endl;
	int a;
	cout << "Non initialized integer = " << a << endl;
	ABEntry abe("abe", "qwe", "0123654");
	NewStruct newStruct;
	cout << "Non initialized struct members: " << newStruct.a << '\t' << newStruct.b << endl; 
	char* pSomeString;
	cout << "Non initialized string: " << pSomeString << endl;
	int arr[10];
	cout << "Non initialized array's member = " << arr[5] << endl;
	BadSiquence bS(0, 1, 2);
}

