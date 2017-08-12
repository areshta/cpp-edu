/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate using correponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                             */                  
/***************************************************************************************************/

//Book:      Effective Modern C++. The first edition.
//Item: #11.  Example 1. Prefer deleted functions to private undefined ones
//Code type: good

#include <iostream>
#include <string>

using namespace std;

// using delete with char specialization
template<typename T>
void OutNonCharPointer(T* ptr)
{
	cout << "Some pointer = 0x" << ptr << endl;
}
template<> void OutNonCharPointer(char* ptr) = delete;


//using delete in glogal fun
void HexOut(int i)
{
	cout << "Some integer i = 0x" << hex << i << endl;
}
void HexOut(double i) = delete; //desabling convertation double to hex

// Using delete in class
class NoCopy
{
public:
	NoCopy() 
	{
	}
	NoCopy(const NoCopy& nc) = delete;				//OK
	NoCopy& operator=(const NoCopy& nc) = delete;	//OK
	string getSome() 
	{ 
		return "Some Out"; 
	} 
private:
};

void SomeFun(NoCopy nc)
{
	cout << nc.getSome() << endl;
}


int32_t main()
{
	cout << "Effective Modern C++. The first edition. Item 11. Example 1. Prefer deleted functions to private undefined ones. Good code." << endl;

	HexOut(555);
	HexOut('a');
	//HexOut(5.555);  // OK-compilation error is here if uncomment

	NoCopy nc1, nc2;
	cout << "Object OK:" << nc1.getSome() << endl;

	//SomeFun(nc1); // OK - compilation error is here if uncomment
	//nc1 = nc2; // OK - compilation error is here if uncomment

	OutNonCharPointer<NoCopy>(&nc1);

	char* pChar = new char[10];
	//OutNonCharPointer<char>(pChar); // OK - compilation error is here if uncomment

	return 0;
}
