#include <iostream>
using namespace std;

int glob1 = 555;

void f()
{
    int stack3 =  555;
    int stack4 =  555;
	cout << "stack3 = " << (unsigned long) &stack3 << endl;
	cout << "stack4 = " << (unsigned long) &stack4 << endl;
}

int main ()
{
	static int stat1 = 555;
    int stack1 =  555;
    int stack2 =  555;
	int* pdin1 =  new int {555};
	int* pdin2 =  new int {555};

	cout << "glob1 = " << (unsigned long) &glob1 << endl;
	cout << "stack1 = " << (unsigned long) &stack1 << endl;
	cout << "stack2 = " << (unsigned long) &stack2 << endl;
	cout << "pdin1 = " << (unsigned long) pdin1 << endl;
	cout << "pdin2 = " << (unsigned long) pdin2 << endl;
	cout << "main = " << (unsigned long) &main << endl;

	f();
	cout << "f = " << (unsigned long) &f << endl;

	cout << "stack1 - glob1 = " << (unsigned long) ((char*)&stack1 - (char*)&glob1) << endl;
	cout << "main - f = " << (unsigned long) ((char*)&main - (char*)&f) << endl;

	return 0;
}
