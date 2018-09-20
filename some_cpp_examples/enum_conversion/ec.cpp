#include <iostream>

using namespace std;

enum EN { a, b, c };

int main()
{
	EN en;
	en = b;
	cout << "b=" << en << endl;
	en =  static_cast<EN>(10);
	cout << "en=" << en << endl;

	return 0;
}
