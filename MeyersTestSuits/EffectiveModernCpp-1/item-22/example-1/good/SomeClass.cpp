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

SomeClass::SomeClass():
m_pImpl(new Impl)
{
}

SomeClass::~SomeClass()
{
}

// supporting moving
SomeClass::SomeClass(SomeClass&& rhs) = default; 
SomeClass& SomeClass::operator=(SomeClass&& rhs) = default; 

// supporting copying
SomeClass::SomeClass(const SomeClass& rhs) 
: m_pImpl(std::make_unique<Impl>(*rhs.m_pImpl))
{}
SomeClass& SomeClass::operator=(const SomeClass& rhs) 
{
	if(this != &rhs)
	{
		*m_pImpl = *rhs.m_pImpl;
	}
	return *this;
}

void SomeClass::ouputData()
{
	cout << m_pImpl->m_sData << endl;
}

