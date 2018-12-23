#include <iostream>
#include "main.h"

using namespace std;

void inputer(int* pa, int* pb)
{
    cout << "Input a: " << endl;
    cin >> *pa;
    cout << "a = " << *pa << endl;

    cout << "Input b: " << endl;
    cin >> *pb;
    cout << "b = " << *pb << endl;
}
