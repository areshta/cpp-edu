
#include <iostream>
#include <array>

using namespace std;

template<int typeSize, typename T>
void initArrayByList(array<T,typeSize>& ar, std::initializer_list<T> ls)
{
      int index = 0;
      for (auto i: ls)
      {
         ar[index] = i;
         ++index;
      }   
}

template<int typeSize, typename ValueType, typename T1, typename T2>
class InterfaceConvertionSupport
{
public: 
   InterfaceConvertionSupport(ValueType initValue, std::initializer_list<T1> ls1, std::initializer_list<T2> ls2)
   : mInitValue {initValue}
   {
      initArrayByList<typeSize, T1>(mIDs1, ls1);
      initArrayByList<typeSize, T2>(mIDs2, ls2); 
      for(int i=0; i< typeSize; ++i)
      {
         mValues[i] = initValue;
      }
   }

   bool setValue(T1 id, ValueType value)
   {
      for(int i=0; i< typeSize; ++i)
      {
         if(mIDs1[i] == id)
         {
            mValues[i] == value;
            return true;
         }
      }
      return false;
   }
   
   T2 convert(T1 id)
   {
      for(int i=0; i< typeSize; ++i)
      {
         if(mIDs1[i] == id)
         {
            return mIDs2[i];
         }
      }     
   }
   
   T1 convert(T2 id)
   {
      for(int i=0; i< typeSize; ++i)
      {
         if(mIDs2[i] == id)
         {
            return mIDs1[i];
         }
      }     
   }
   
   private:
      
      const ValueType mInitValue;
      
      array<ValueType, typeSize> mValues;
      array<T1,typeSize> mIDs1;
      array<T2,typeSize> mIDs2;   
};

enum Aen {a0 = 3, a1 = 4 , a2 = 2, a3 = 10};
enum Ben {b0 = 20 , b1 = 22,  b2 = 25 , b3 = 27};

constexpr std::initializer_list<Aen> lsAen = {a0, a1, a2, a3};
constexpr std::initializer_list<Ben> lsBen = {b0, b1, b2, b3};
constexpr std::initializer_list<int> lsInt = {1, 2, 3, 4};
static_assert( lsAen.size() == lsBen.size() );

class B
{
public:
   B(): 
   a { -1, lsAen, lsBen }
   , a1 { -1, lsAen, lsInt }
   {
      cout << "Convert a2 to b2 " << a.convert(a2) << endl;
      cout << "Convert a3 to b3 " << a.convert(a3) << endl;
      cout << "Convert b1 to a1 " << a.convert(b1) << endl;
      cout << "Convert b3 to a3 " << a.convert(b3) << endl;
      
      cout << "a1>>Convert a2 to 2 " << a1.convert(a2) << endl;
      cout << "a1>>Convert a3 to 3 " << a1.convert(a3) << endl;
      cout << "a1>>Convert 2 to a1 " << a1.convert(2) << endl;
      cout << "a1>>Convert 4 to a3 " << a1.convert(4) << endl;
           
      
   }
private: 
   InterfaceConvertionSupport < lsAen.size(), int, Aen, Ben> a;
   InterfaceConvertionSupport < lsAen.size(), int, Aen, int> a1;
};

int main(int argc, char** argv) 
{
   B b;
   return 0;
}

