
#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "fraction.h"

using namespace std;

fraction::fraction(long num, unsigned long den) :_num(num)
{

 if (den==0)
 {
  throw(42);
 }
 else
 {
  _den = den;
 }
 this->simplifie();
}

fraction::fraction(long num):_num(num),_den(1)
{}

fraction::fraction(const fraction &f):_num(f._num),_den(f._den)
{}

fraction::~fraction()
{}

ostream& operator<<(ostream &os, const fraction &f)
{
 os.width(6);
 os << right << f._num;

 if (f._den !=1)
 {
     os << "/";
     os.width(6);
     os << left << f._den;
 }
 else
 {
     os << setw(7) << "       ";
 }
 
 return os;
}

istream& operator>>(istream &is, fraction &f)
{
 is >> f._num;
 is >> f._den;
 return is;
}

fraction operator+(const fraction &f1, const fraction &f2)
{
 fraction f((f1._num*f2._den)+(f1._den*f2._num),f1._den * f2._den);;
 
 f.simplifie();

 return f;
}

fraction operator-(const fraction&f1, const fraction &f2)
{
 fraction f((f1._num*f2._den)-(f1._den*f2._num),f1._den * f2._den);;

 f.simplifie();

 return f;
}

fraction operator*(const fraction &f1, const fraction &f2)
{
fraction f(f1._num*f2._num,f1._den * f2._den);;

 f.simplifie();

 return f;
}


fraction operator/(const fraction &f1, const fraction &f2)
{
 
 fraction f = (f1*f2.inverse());
 
 f.simplifie();
 
 return f;
 
}

double fraction::eval() const
{
 return (double)_num / (double)_den;
}

void fraction::simplifie()
{
 
 long a,b,tmp, rem;
 long pgcd;
 
 a = this->_num;
 b = this->_den;

 a = (a<0 ? -a:a);

 if (b>a)
 {
  tmp = a;
  a = b;
  b = tmp;
 }
 // calcul du pgcd

 while (b != 0)
 {
  rem = a%b;
  
  a=b;
  b=rem;
 }

 pgcd = a;

 _num = _num / pgcd;
 _den = _den / pgcd;

 return;
}

fraction fraction::inverse() const
{

 fraction temp;

 temp._num = (this->_num < 0 ? -1*_den : _den);
 temp._den = (this->_num < 0 ? -1*_num : _num);

  return temp;
}
