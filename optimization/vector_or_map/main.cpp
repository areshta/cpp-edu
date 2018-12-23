/* 
 * File:   main.cpp
 * Author: alexey
 *
 * Created on October 1, 2018, 5:45 PM
 */

#include <iostream>
#include <array>
#include <unordered_map>
#include <chrono>
#include <iomanip>
#include <vector>

using namespace std;
using namespace std::chrono;

class VectorConv
{
   public:
      VectorConv(int n)
      {
         for(int i=0; i< n; ++i)
         {
            mVectorIF1.push_back(1001+i);
            mVectorIF2.push_back(2001+i);
         }
      }

      int convertFromIF1(int el)
      {
         int index = 0;
         for(auto i: mVectorIF1)
         {
            if( i == el)
            {
               return mVectorIF2[index];
            }
            ++index;
         }
      }
      int convertFromIF2(int el)
      {
         int index = 0;
         for(auto i: mVectorIF2)
         {
            if( i == el)
            {
               return mVectorIF1[index];
            }
            ++index;
         }
      }
   private:
      vector<int> mVectorIF1;
      vector<int> mVectorIF2;
   };



class MapConv
{
   public:
      MapConv(size_t n)
      {
         for(int i=0; i<n; ++i)
         {
            mMapKeyIF1[1001+i] = 2001+i;
            mMapKeyIF2[2001+i] = 1001+i;
         }
      }
      int convertFromIF1(int el)
      {
         return mMapKeyIF1[el];
      }
      int convertFromIF2(int el)
      {
         return mMapKeyIF2[el];
      }
   private:
      unordered_map<int,int> mMapKeyIF1; 
      unordered_map<int,int> mMapKeyIF2; 
};

int main(int argc, char** argv) 
{
       
   
   volatile int k = 0;
   volatile int l = 0;
   const int bigcount = 50000;  
    
   for(int i=2; i <50; i+=1){
      
      VectorConv  arVector (i);
      MapConv     mpConv(i);

      milliseconds timeAr1 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
      for(int j=0; j<=i; j++ )
      {
         int ID1 = 1001+j;
         int ID2 = 2001+j;
         for(int big = 0; big < bigcount; ++big)
         {
            k = arVector.convertFromIF1(ID1) ;
            l = arVector.convertFromIF2(ID2) ;
         }
      }
      milliseconds timeAr2 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());

      milliseconds timeMp1 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
      for(int j=0; j<=i; j++ )
      {
         int ID1 = 1001+j;
         int ID2 = 2001+j;
         for(int big = 0; big < bigcount; ++big)
         {
            k = mpConv.convertFromIF1(ID1) ;
            l = mpConv.convertFromIF2(ID2) ;
         }
      }
      milliseconds timeMp2 = duration_cast< milliseconds >(system_clock::now().time_since_epoch());
      
      cout << "Elements counter = " << setw(10) << i << "\t\tArMs/MpMs = " << (timeAr2-timeAr1)*1.0/(timeMp2 -timeMp1) << endl;
   }      
         
   return 0;
}

