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
private : // déclare variable
    T a,b,c;
    T x1,x2;
public :
    //constructeurs
    equation();
    equation(T, T, T);

    // destructeurs
    ~equation();

    friend ostream& operator<< <T>(ostream& os, const equation<T>&);

    void naiveSolve();
    void cleverSolve();

};

// template method implementation
// not to be compiled from a separate cpp file !

template <typename T> equation<T>::equation()
{
    //constructeurs null
    a = b = c = (T)0;
    x1 = x2 = (T)0;
}

template <typename T> equation<T>::~equation()
{
    // destructeurs
}

template <typename T> equation<T>::equation(T pa, T pb, T pc):a(pa),b(pb),c(pc)
{
    // constructeurs prenant en compte les variables

}

template <typename T> ostream& operator<<(ostream& os,const equation<T> &e)
{
    os << e.a <<"x^2 + " << e.b << "x + " << e.c;
    os << endl << "x1 =" << e.x1 << endl << "x^2 =" << e.x2 << endl;
    return os;
}

template <typename T> void equation<T>::naiveSolve()
{
    double delta = b*b - 4.0*a*c;

    if (delta > 0)
    {
        double x1 = (-b-sqrt(delta))/(2*a);
        double x2 = (-b+sqrt(delta))/(2*a);
        cout << "Il y a 2 solutions, x1 = " << x1 << "x2 = " << x2 << endl;
    }

    else if (delta == 0)
    {
        double x = - b / 2*a;
        cout << "il y a 1  solution, x = " << x << endl;
    }

    else
        cout << "Il n y a pas de solution" << endl;

}


template <typename T> void equation<T>::cleverSolve()
{
    double delta = b*b - 4.0*a*c;

    if (delta > 0)
    {
        double x1 = (-b-sqrt(delta))/(2*a);
        double x2 = c / (a * x1);
        cout << "Il y a 2 solutions, x1 = " << x1 << "x2 = " << x2 << endl;
    }

    else if (delta == 0)
    {
        double x = - b / 2*a;
        cout << "il y a 1  solution, x = " << x << endl;
    }

    else
        cout << "Il n y a pas de solution" << endl;
}


#endif // EQU_H_INCLUDED
