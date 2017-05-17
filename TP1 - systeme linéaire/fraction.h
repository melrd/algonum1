#ifndef FRACTION
#define FRACTION "__FRACTION"

#include <iostream>

using namespace std;

class fraction
{

   private :
           long 			_num;
           unsigned long 	_den;

           void simplifie();
           fraction inverse() const;

   public :
          fraction(long, unsigned long);
          fraction(long=0);
          fraction(const fraction &);
          ~fraction();
          friend ostream& operator<<(ostream &os, const fraction &);
          friend istream& operator>>(istream &is, fraction &);
          
          friend fraction operator+(const fraction &, const fraction &);
          friend fraction operator-(const fraction &, const fraction &);
          friend fraction operator*(const fraction &, const fraction &);
          friend fraction operator/(const fraction &, const fraction &);

          friend bool operator==(const fraction &f1, const fraction &f2)
          {
           return (f1._num*f2._den == f1._den*f2._num);
          }
          
          friend bool operator<(const fraction &f1, const fraction &f2)
          {
           return (f1.eval() < f2.eval());
          }
          
          friend bool operator>(const fraction &f1, const fraction &f2)
          {
           return (f1.eval() > f2.eval());
          }
          
          friend bool operator<=(const fraction &f1, const fraction &f2)
          {
           return ((f1 < f2)||(f1==f2));
          }
          
          friend bool operator>=(const fraction &f1, const fraction &f2)
          {
           return ((f1 > f2)||(f1 == f2));
          }
          
          friend bool operator!=(const fraction &f1, const fraction &f2)
          {
           return ((f1==f2)==false);
          }
          
          double eval() const;
};

#endif
