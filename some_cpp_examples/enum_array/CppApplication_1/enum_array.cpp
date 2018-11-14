/* 
 * File:   enum_array.cpp
 * Author: alexey
 *
 * Created on September 24, 2018, 3:56 PM
 */


#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <array>
#include <map>

using namespace std;

enum En0 {a, b, c, d, e};
enum En1 {a1, b1, c1, d1, e1, f1};
enum En2 {a2, b2, c2, d2 = 100 };
enum En3 {a3 = 3 , b3 = 2, c3 = 1, d3 = 0 };
enum En4 {a4, b4, c4, d4, e4, f4 = 20};
enum En5 {a5};
enum En6 {a6, b6, c6, d6, e6, f6, g6, h6, i6, j6, k6};
enum En7 {a7=-10, b7, c7=-1, d7, e7};

enum EnStep1 {aa , bb, cc, dd,  ee, ff };

template<typename... Args>
constexpr int enum_size(Args... args)
{
   return sizeof...(args);
}

template<typename T>
constexpr int  enum_summ(T x)
{
   return x;
}

template<typename T, typename... Args>
constexpr int enum_summ(T first, Args... args)
{
   return first + enum_summ(args...);
}

template<typename T>
constexpr bool  enum_no_negative(T x)
{
   return x >= 0;
}


template<typename T, typename... Args>
constexpr bool enum_no_negative(T first, Args... args)
{
   return (first >= 0) && enum_no_negative(args...);
}

template<typename T>
constexpr int  enum_min(T x)
{
   return x >= 0;
}


template<typename T, typename... Args>
constexpr int enum_min(T first, Args... args)
{
   return first < enum_min(args...) ? first : enum_min(args...);
}

//template<typename T>
//constexpr bool enum_step1(T x)
//{
//   return x;
//}
//
//template<typename T>
//constexpr bool enum_step_pare(T x1, T x2)
//{
//   return x2-x1 == 1;
//}
//
//template<typename T, typename... Args>
//constexpr bool enum_step1(T first, Args... args)
//{
//   return (enum_step_pare(first, enum_step1(args...))) && enum_step1(args...);
//}
//

template<typename... Args>
constexpr bool enumIsArrayable(Args... args)
{
   return enum_no_negative(args...) && (enum_summ(args...) - enum_size(args...)*(enum_size(args...)-1)/2 == 0);
}

#define listEnum1 a1, b1, c1, d1, e1, f1
typedef std::conditional<enumIsArrayable(listEnum1) , 
                        array<int, enum_size(listEnum1)> , 
                        map<En1,int> >::type UniCollection1;

#define listEnum2 a2, b2, c2, d2
typedef std::conditional<enumIsArrayable(listEnum2) , 
                        array<int, enum_size(listEnum2)> , 
                        map<En2,int> >::type UniCollection2;

#define CreateUniCollection(Type, ...) \
typedef std::conditional<enumIsArrayable(__VA_ARGS__) , \
                        array<int, enum_size(__VA_ARGS__)> , \
                        map<Type,int> >::type UniCollection##Type; \
                        
 
int main(int argc, char** argv) {

   constexpr int min_value = enumIsArrayable(aa , bb, cc, dd,  ee, ff);
   
   cout << "No negative " << enum_no_negative(a7, b7, c7, d7, e7) << endl;
   cout << "Enum min a7...e7 " << enum_min(a7, b7, c7, d7, e7)<< endl;
//   cout << "Enum step1 aa...ff " << enum_step1(aa , bb, cc, dd,  ee, ff)<< endl;
   
   cout << "size = " << enum_size(a,b,c,d,e)<< endl;
   cout << "summ = " << enum_summ(a,b,c,d,e)<< endl;
   cout << "Good: isArrayable a...e " << enumIsArrayable(a,b,c,d,e)<< endl;
   
   cout << "Good: isArrayable a1...f1 " << enumIsArrayable(a1, b1, c1, d1, e1, f1)<< endl;
   cout << "Bad: isArrayable a2...d2 " << enumIsArrayable(a2, b2, c2, d2)<< endl;
   cout << "Good: isArrayable a3...d3 " << enumIsArrayable(a3, b3, c3, d3)<< endl;
   cout << "Bad: isArrayable a7...e7 " << enumIsArrayable(a7, b7, c7, d7, e7)<< endl;
   cout << "Bad: isArrayable a7...e7 " << min_value << endl;
   
   
   
   // solution using conditional typedef
   
   UniCollection1 Uc1;
   
   std::cout << "Type of Uc1 =" << typeid(Uc1).name() << '\n';

   UniCollection2 Uc2;

   std::cout << "Type of Uc2 =" << typeid(Uc2).name() << '\n';
   
   // solution using macros + conditional typedef
   
   CreateUniCollection(En0, a, b, c, d, e);
   UniCollectionEn0 Uc0 = {1, 1, 2, 2, 3};
   
   std::cout << "Type of Uc0 =" << typeid(Uc0).name() << '\n';
   
   for(auto i: Uc0)
   {
      cout << "Uc0 Ini = " << i << endl;
   }

   CreateUniCollection(En4, a4, b4, c4, d4, e4, f4);
   UniCollectionEn4 Uc4 ={{a4,0},{b4,0}, {c4,1}, {d4,1}, {e4,1}, {f4,1}};

   std::cout << "Type of Uc4 =" << typeid(Uc4).name() << '\n';

   for(auto& el: Uc4)
   {
      cout << "Uc4 Ini = " << el.second << endl;
   }

   CreateUniCollection(En5, a5);
   UniCollectionEn5 Uc5 = {0};
   
   std::cout << "Type of Uc5 =" << typeid(Uc5).name() << '\n';

   CreateUniCollection(En6, a6, b6, c6, d6, e6, f6, g6, h6, i6, j6, k6);
   UniCollectionEn6 Uc6;

   std::cout << "Type of Uc6 =" << typeid(Uc6).name() << '\n';
     
   return 0;
}

