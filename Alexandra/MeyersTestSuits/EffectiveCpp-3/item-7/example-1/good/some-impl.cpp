/***************************************************************************************************/
/* Class implementation.               		                                                       */                  
/***************************************************************************************************/

//Item: #7.  Declare destructors virtual in polymorphic base classes.
//Code type: good

#include "some-header.h"

using std::cout;
using std::endl;

SomeBase::SomeBase() 
{
	cout << "SomeBase constructor" << endl;
}
SomeBase::~SomeBase()
{
	cout << "SomeBase destructor" << endl;
}

Child1::Child1()
{
	mpStr = new char[mBuffSize];
	cout << "CHild1 constructor" << endl;
}
Child1::~Child1()
{
	delete[] mpStr;
	cout << "Child1 desatructor" << endl;
}

Child2::Child2()
{
	mpStr = new char[mBuffSize];
	cout << "Child2 constructor" << endl;
}
Child2::~Child2()
{
	delete[] mpStr;
	cout << "Child2 destructor" << endl;
}

