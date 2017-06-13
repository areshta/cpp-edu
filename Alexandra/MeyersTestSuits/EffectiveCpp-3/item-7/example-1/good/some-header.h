/***************************************************************************************************/
/* Class definitions.                  		                                                       */                  
/***************************************************************************************************/

//Item: #7.  Declare destructors virtual in polymorphic base classes.
//Code type: good

#ifndef SOME_HEADER
#define SOME_HEADER

#include <iostream>

using std::cout;
using std::endl;

class SomeBase {
public:
	SomeBase();
	virtual ~SomeBase();
protected:
	const int mBuffSize = 100;
};

class Child1: public SomeBase 
{
public:
	Child1();
	Child1(const Child1 &obj);
	const Child1& operator=(const Child1 &obj);
	~Child1();
private:
	char* mpStr = nullptr;
};

class Child2: public SomeBase 
{
public:
	Child2();
	Child2(const Child2 &obj);
	const Child2& operator=(const Child2 &obj);
	~Child2();
private:
	char* mpStr = nullptr;
};
#endif
