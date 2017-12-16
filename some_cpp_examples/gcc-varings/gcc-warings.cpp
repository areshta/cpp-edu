#include <iostream>

using namespace std;

int32_t main()
{
    int a = 7.2;
    int b = 0;
    float c = 3.2;

    a = c;

    c; // -Wunused-value

    if( 0 )
    {
//example of disabling
//#pragma GCC diagnostic push
//#pragma GCC diagnostic ignored "-Wdiv-by-zero"
        a /= 0; // -Wdiv-by-zero
//#pragma GCC diagnostic push
    }
    else
    {
        a /= b; // missing div by zero
    }
    
    cout << "gcc warnings control. a =" << a << endl;
    
}
