#pragma once

class SomeClass 
{
public:
	SomeClass();
	~SomeClass();
	void ouputData();
private:
	struct Impl; 
	Impl *m_pImpl;
};
