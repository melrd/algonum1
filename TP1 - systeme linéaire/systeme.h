#ifndef SYSTEME_H_INCLUDED
#define SYSTEME_H_INCLUDED

#include <iostream>

using namespace std;


// forward declarations for ostream& operator

template <typename T> class Systeme;
template <typename T> ostream& operator<<(ostream&, const Systeme<T> &);
template <typename T> istream& operator>>(istream&, Systeme<T>&);


template <typename T> class Systeme
{
    private :
        T**     _values;
        long    _size;

        T*      _solution;

        long    *_permut;

        void alloueSysteme(long);

        void pivote(long, long);
        void echangeLignes(long, long);
        void echangeColonnes(long, long);

    public :
        Systeme();
        ~Systeme();

        friend ostream& operator<< <T>(ostream& os, const Systeme<T>&);
        friend istream& operator>> <T>(istream& is, Systeme<T> &);

        void triangGauss();
        void triangGaussPivotPartiel();
        void triangGaussPivotTotal();

        void iterJacobi();
        void iterGaussSeidel();

        void calculeResultats();

};

#endif // SYSTEME_H_INCLUDED
