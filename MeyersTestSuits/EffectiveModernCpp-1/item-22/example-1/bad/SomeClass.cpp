#include "SomeClass.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
	
struct SomeClass::Impl
{
	string m_sData = "Some super-data";
}; 

SomeClass::SomeClass()
{
	m_pImpl =  new Impl; //Bad: using row pointers
}
SomeClass::~SomeClass()
{
	delete m_pImpl; //Bad: using row pointers
}
void SomeClass::ouputData()
{
	cout << m_pImpl->m_sData << endl;
}

