#include <iostream>
#include "main.h"

using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    inputer(&a, &b);
    cout << summator(a, b) << endl;

    return 0;
}

