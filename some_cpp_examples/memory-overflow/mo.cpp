#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

void test_oweflow()
{
	string big(1000000,'z');
	vector<string> vec;
	int counter = 0;
	try
	{
		while(true)
		{
			vec.push_back(big);
			cout << ".";
			++counter;
		}
	}
	catch(const std::out_of_range& e)
	{
		cout << "\nVector is out of range! Counter = " << counter <<  "MB" << endl;
	}
	catch(...)
	{
		cout << "\nOther exception!" << endl;
	}	
}

int main()
{
	cout << "Test vector overflow" << endl;
	test_oweflow();
	return 0;
}
