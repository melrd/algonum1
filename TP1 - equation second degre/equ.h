#ifndef EQU_H_INCLUDED
#define EQU_H_INCLUDED

#include <iostream>
#include <cmath>

using namespace std;

// forward declarations for ostream& operator

template <typename T> class equation;
template <typename T> ostream& operator<<(ostream&, const equation<T> &);

// template class definition

template <typename T> class equation
{
private :
    T a,b,c;
    T x1,x2;
public :
    equation();
    equation(T, T, T);

    ~equation();

    friend ostream& operator<< <T>(ostream& os, const equation<T>&);

    void naiveSolve();
    void cleverSolve();
   
 
};

// template method implementation
// not to be compiled from a separate cpp file !

template <typename T> equation<T>::equation()
{
    a = b = c = (T)0;
    x1 = x2 = (T)0;
}

template <typename T> equation<T>::~equation()
{

}

template <typename T> equation<T>::equation(T pa, T pb, T pc):a(pa),b(pb),c(pc)
{

}

template <typename T> ostream& operator<<(ostream& os,const equation<T> &e)
{
    os << e.a <<"x^2 + " << e.b << "x + " << e.c;
    os << endl << "x1 =" << e.x1 << endl << "x^2 =" << e.x2 << endl;
    return os;
}

template <typename T> void equation<T>::naiveSolve()
{
    // implement here the classical solving algorithm
    /* A vous de jouer */
}

 
template <typename T> void equation<T>::cleverSolve()
{
    // implement here the clever solving algorithm
     /* A vous de jouer */
}


#endif // EQU_H_INCLUDED
