#include <iostream>
#include <fstream>
#include <string>
#include <memory>

using namespace std;

class A
{
public:
	A(const string& s): 
	m_note(s)
	{ 
		m_o.open(fname, fstream::app);
		if( m_first )
		{
			m_o << "===== Begin ======"<< endl;
			m_first = false;
		}
		m_o << "Constructor "<< m_note << endl;
	}
	~A()
	{
		m_o << "Destructor "<< m_note << endl;
		m_o.close();
	}
private:
	ofstream m_o;
	const string fname = "log.txt";
	const string m_note;
	static bool m_first;
};

bool A::m_first = true;

A a("a glob");

int main()
{
	A a1("a auto");
	static A a2("a static");
	unique_ptr<A> a3 (new A("a unique_ptr") );

	return 0;
}
