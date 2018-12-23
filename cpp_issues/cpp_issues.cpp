#include <iostream>
using namespace std;

void out(double a, double b)
{
	cout << "\n150 + 150 = " << a + b << " ?!!!   :-(" << endl;
}

int main() 
{
    //overflow issue
	int8_t a = 150, b=150;
	cout << "\n150 + 150 = " << a + b << " ?!!!   :-(" << endl;
    cout << "\n150 + 150 = " << static_cast<int16_t>(a) + static_cast<int16_t>(b) << " ???" << endl;
	float c = 1.*a;
	float d = 1.*b;
	cout << "\n150 + 150 = " << c + d  << " ???" << endl;
	double e = 1.*static_cast<double>(a);
	double f = 1.*static_cast<double>(b);
	cout << "\n150 + 150 = " << e + f  << " ???" << endl;
    double r = e+f;
	cout << "\n150 + 150 = " << r  << " ???" << endl;

    out(e,f);

    return 0;
}

