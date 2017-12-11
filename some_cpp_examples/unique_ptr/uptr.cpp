// Demonstration of the error:
// unique_ptr object was inited in the block by the pointer that is living longer
// additionaly some strange behavior present p[0] is changed while deleting by unique_ptr
// the pointer is not changed  


#include <iostream>
#include <memory>

using namespace std;

int32_t main()
{
    int *p = new int[20];
    p[0]=5;

    cout << "1.p=" << p << endl;
    {
        unique_ptr<int> up(p);
        up.get()[0]=7; 
    }

    cout << "2.p=" << p << endl;

    for(int i=1; i<20; i++)
    {
        p[i]=i;
    }
 
    for(int i=0; i<20; i++)
    {
        cout << p[i] << endl;
    }  
    
    delete p;
     
    cout << "Exit" << endl;
    return 0;
}
