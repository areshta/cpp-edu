/****************************************************************************************************/
/* Examples created according items from Scott Meyers books for testing Static code analyzers       */
/*                                                                                                  */ 
/* Warnings: This code demonstrate using corresponding item. Please ignore other possible warnings. */
/*           c++14 standard is assumed                                                              */                  
/* Author:   Oleksii Reshta	                                                                        */
/****************************************************************************************************/

#include <iostream>
#include <string>
#include <utility>

using std::cout;
using std::endl;
using std::string;
using std::move;


const string sInfo =
/*****************************************************************************************************/
	" Book:       Effective Modern C++. The first edition.                     			            \n"
	" Item: #23.  Example 2. Understand std::move and std::forward                                  \n"
	" Code type:  good.                                               			 	              \n\n" 
/****************************************************************************************************/
;

class SpecSniffer
{
public:
    SpecSniffer()
    {
        cout << "Default Constructor " << "(" << m_str << ")" << endl;
    }
    SpecSniffer(string s):
        m_str {s}
    {
        cout << "Constructor by string" << "(" << m_str << ")" << endl;
    }
    SpecSniffer(const SpecSniffer& sf):
        m_str {sf.m_str}    
    {
        cout << "Copy Constructor" << "(" << m_str << ")" << endl;
    }
    SpecSniffer(SpecSniffer&& sf):
        m_str(move(sf.m_str))
    {
        cout << "Move Constructor" << "(" << m_str << ")" << endl;
    }    
    SpecSniffer& operator=(const SpecSniffer& sf)
    {
        if (this == &sf) {
            return *this;
        }
        m_str = sf.m_str;
       cout << "Assignment operator" << "(" << m_str << ")" << endl;
       return *this;
    }    
    SpecSniffer& operator=(SpecSniffer&& sf)
    {
        m_str =  move (sf.m_str);
        cout << "Move assignment operator" << "(" << m_str << ")" << endl;
        return *this;
    }   
    void out()
    {
        cout << "SpecSniffer value: " << m_str << endl;
    }
private:
    string m_str;
};


class GoodMoving
{
public: 
    GoodMoving()
    {
    }
    GoodMoving(SpecSniffer&& sf):
        m_sf(move(sf)) // OK
    {
    }
private:
    SpecSniffer m_sf;
};


int32_t main()
{
	cout << sInfo << endl;

    // special funcrions working show
    SpecSniffer s1 ("some value");
    SpecSniffer s2 {s1};
    SpecSniffer s3 {move(s2)};
    SpecSniffer s4;
    s4 = s3;
    SpecSniffer s5;
    s5 = move(s3);

    s5.out();

    cout << "\n\nGood moving example: " << endl;

    GoodMoving wm1;
    GoodMoving wm2(move(wm1));

	return 0;
} 
