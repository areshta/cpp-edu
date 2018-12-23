#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

const char* const stst = "test";

class A
{
public:
   A()
   {
      cout << "Constructor"<<endl;
      mBuff = new char[strlen(stst)+1];
      strcpy(mBuff,stst);        
   }
   ~A()
   {
      delete mBuff;
   }
   A(const A& a)
   {
      cout << "Copy constructor"<<endl;
      mBuff = new char[strlen(a.mBuff)+1];
      strcpy(mBuff,a.mBuff);        
   }
   A& operator=(const A& a)
   {
      cout << "operator = "<<endl;
      mBuff = new char[strlen(a.mBuff)+1];
      strcpy(mBuff,a.mBuff);        
   }
private:
   char* mBuff;
};

int main(int argc, char** argv) {
   
   vector<A> v = {A(),A(),A()};
   
   cout << "==== Copying ====" <<endl;
   
   vector<A> v1 = v;

   cout << "==== Copying again ====" <<endl;
   
   v = v1;
   
   return 0;
}

