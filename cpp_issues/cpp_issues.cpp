#include <iostream>
using namespace std;


int main() 
{
    //overflow issue
	uint8_t a = 150, b=150;
    uint8_t c = a+b;
	cout << "\n150 + 150 = " << static_cast<int>(c) << " ?!!!   :-(" << endl;
    cout << "\n150 + 150 = " << static_cast<int16_t>(a) + static_cast<int16_t>(b) << " ???" << endl;
	float cc = 1.*a;
	float d = 1.*b;
	cout << "\n150 + 150 = " << cc + d  << " ???" << endl;
	double e = 1.*static_cast<double>(a);
	double f = 1.*static_cast<double>(b);
	cout << "\n150 + 150 = " << e + f  << " ???" << endl;
    double r = e+f;
	cout << "\n150 + 150 = " << r  << " ???" << endl;

    return 0;
}

