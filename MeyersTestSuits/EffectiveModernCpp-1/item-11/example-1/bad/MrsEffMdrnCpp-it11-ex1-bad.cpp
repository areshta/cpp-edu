/***************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers      */
/*                                                                                                 */ 
/* Warnings: This code demonstrate using correponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                             */                  
/***************************************************************************************************/

//Book:      Effective Modern C++. The first edition.
//Item: #11.  Example 1. Prefer deleted functions to private undefined ones
//Code type: bad

#include <iostream>
#include <string>

using namespace std;

class NoCopy
{
public:
	NoCopy() 
	{
	}
	string getSome() 
	{ 
		return "Some Out"; 
	} 
private:
	NoCopy(const NoCopy& nc);				//bad, instruction delete is prefered
	NoCopy& operator=(const NoCopy& nc);	//bad, instruction delete is prefered
};

void SomeFun(NoCopy nc)
{
	cout << nc.getSome() << endl;
}


int32_t main()
{
	cout << "Effective Modern C++. The first edition. Item 11. Example 1. Prefer deleted functions to private undefined ones. Bad code." << endl;

	NoCopy nc1, nc2;
	cout << "Object OK:" << nc1.getSome() << endl;

	//SomeFun(nc1); // OK-compilation error is here if uncomment
	//nc1 = nc2; // OK-compilation error is here if uncomment

	return 0;
}
