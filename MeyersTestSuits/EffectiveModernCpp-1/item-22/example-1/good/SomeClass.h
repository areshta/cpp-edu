#pragma once

#include <memory>

using std::unique_ptr;

class SomeClass 
{
public:
	SomeClass();
	~SomeClass();
	
	//supporting moving
	SomeClass(SomeClass&& rhs); 
	SomeClass& operator=(SomeClass&& rhs); 

	//supporting copying
	SomeClass(const SomeClass& rhs);
	SomeClass& operator=(const SomeClass& rhs); 

	void ouputData();
private:
	struct Impl; 
	unique_ptr<Impl> m_pImpl; //OK: using smart pointer
};
