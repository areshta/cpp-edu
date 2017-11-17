/****************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers       */
/*                                                                                                  */ 
/* Warnings: This code demonstrate using corresponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                              */                  
/* Author:   Oleksii Reshta	(аleх.rеshtа@gmаil.com - email is protected from bots, 					*/
/*                           please enter the address manualy, copy/past will not working)          */
/****************************************************************************************************/

#include <iostream>
#include <string>
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;

const string sInfo =
/*****************************************************************************************************/
	" Book:       Effective Modern C++. The first edition.                     			            \n"
	" Item: #20.  Example 1. Use std::weak_ptr for std::shared_ptrlike pointers that can dangle.	\n"
	" Code type:  bad.                                               			 	              \n\n" 
/****************************************************************************************************/
;

class SomeObserever_1;

class ClassName
{
public:
	ClassName(const string& sName):
		m_sName(sName)
	{
        cout << m_sName << " constrctor" << endl;
	}
	string touchObject()
	{
		return m_sName + " is toucted";
	}

	virtual ~ClassName()
	{
        cout << m_sName << " destructor" << endl;
	}

protected:
	string m_sName;
};

class SomeObserever_1;

class SomeShared: public ClassName
{
    public:
    SomeShared():
		ClassName("SomeShared")
    {
    }
 	void setObserver1( shared_ptr<SomeObserever_1> psO1 )
	{
		m_psO1 = psO1;
	}

 	shared_ptr<SomeObserever_1>& getObserver1pointer()
	{
		return m_psO1;
	}

private:

	shared_ptr<SomeObserever_1> m_psO1; // Bad idea: two objects will have shatred crosspointers

};


class SomeObserever_1: public ClassName
{
    public:
    SomeObserever_1():
		ClassName("SomeObserever_1")
 
    {
    }

 	void setShared( shared_ptr<SomeShared> psH1 )
	{
		m_psH = psH1;
	}

	void  touchShared()
	{
		cout << m_sName << ":" << m_psH->touchObject() << endl;
	}	

private:

	shared_ptr<SomeShared> m_psH;
};

class SomeObserever_2: public ClassName
{
    public:
    SomeObserever_2():
		ClassName("SomeObserever_2")
 
    {
    }

 	void setShared( shared_ptr<SomeShared> psH1 )
	{
		m_psH = psH1;
	}
private:

	shared_ptr<SomeShared> m_psH;
};


int32_t main()
{
	cout << sInfo << endl;

	shared_ptr<SomeShared> psH(new SomeShared);
	shared_ptr<SomeObserever_1> psO1(new SomeObserever_1);
	shared_ptr<SomeObserever_2> psO2(new SomeObserever_2);

	psO1->setShared(psH); 	// Error: SomeShare and SomeObserver have sharing crosspoints. 
							// They never will be destructed!
	psO1->touchShared();

	psH->setObserver1(psO1); 
	cout << "Next touch: " << 	psH->getObserver1pointer()->touchObject() << endl;
	
	return 0;
} 
