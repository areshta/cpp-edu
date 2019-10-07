#include <iostream>
#include <cmath>
#include <limits>


// Comparing on equality float/double values. Assumption: eps > 0.
template<class T>
inline bool float_eq(T x, T y, T eps = static_cast<T>(0.001) )
{    
   T rel_eps = eps * std::max(fabs(x), fabs(y));
   return std::fabs(x - y) < rel_eps ;
}


template<class T1, class T2>
inline bool some_eq(T1 x, T2 y, long double eps = 0.001 )
{ 
   if(x==y)
   {
      return true;
   }

   long double x1 = static_cast<long double>(x);
   long double y1 = static_cast<long double>(y);

   long double rel_eps = eps * std::max(fabs(x1), fabs(y1));
   return std::fabs(x1 - y1) <= rel_eps ;
}


int main()
{
   std::cout << "Invalid comparing float values example. " << std::endl;

   double a = 1./3.;
   float b = a;
   std::cout << "a = " << a << std::endl;
   std::cout << "b = " << b << std::endl;
   std::cout << "(a == b) = " << (a==b) << " : It is 'false', but expected 'true'!" << std::endl;

   double a1 = 10. * 1./3.;
   double b1 = 1. / 3. / 0.1;
   std::cout << "a1 = " << a1 << std::endl;
   std::cout << "b1 = " << b1 << std::endl;
   std::cout << "(a1 == b1) = " << (a1 == b1) << " : It is 'false', but expected 'true'!" << std::endl;

   double a2 = 0.1 + 0.2;
   double b2 = 0.3;
   std::cout << "a2 = " << a2 << std::endl;
   std::cout << "b2 = " << b2 << std::endl;
   std::cout << "(a2 == b2 = " << (a2 == b2) << " : It is 'false', but expected 'true'!" << std::endl;

   long double PI1 = acosl(-1.0L);
   double PI2 = acos(-1.0L);
   std::cout << "PI1 = " << PI1 << std::endl;
   std::cout << "PI2 = " << PI2 << std::endl;
   std::cout << "(PI1 == PI2) = " << (PI1 == PI2) << " : It is 'false', but expected 'true'!" << std::endl;


    std::cout << some_eq(a, b) << "==" << 1 << std::endl;
    std::cout << some_eq(a1, b1) << "==" << 1 << std::endl;
    std::cout << some_eq(a2, b2) << "==" << 1 << std::endl;
    std::cout << some_eq(0, 0.) << "==" << 1 << std::endl;
    std::cout << some_eq(0., 0) << "==" << 1 << std::endl;
    std::cout << some_eq(0.f, 0) << "==" << 1 << std::endl;
    std::cout << some_eq(PI1, PI2, std::numeric_limits<double>::epsilon() ) <<  "==" << 1 << std::endl;
    std::cout << some_eq(1.01, 1.) <<  "==" << 0 << std::endl;
    std::cout << some_eq(1.01, 1., 0.1) <<  "==" << 1 << std::endl;
    std::cout << some_eq(-1., 1.) <<  "==" << 0 << std::endl;
    std::cout << some_eq(100., 1.) <<  "==" << 0 << std::endl;
    std::cout << some_eq(100., 1., 200.) <<  "==" << 1 << std::endl;
    std::cout << some_eq(1.e200, 1.e200+000.1) <<  "==" << 1 << std::endl;
    std::cout << some_eq(1.e200, 1.e200+1.) <<  "==" << 1 << std::endl;
    std::cout << some_eq(1.e200, 1.e199) <<  "==" << 0 << std::endl;

    return 0;
}

