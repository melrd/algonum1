#ifndef POLYNOMENEWTON_H_INCLUDED
#define POLYNOMENEWTON_H_INCLUDED


#include "Polynome.h"

template <typename T> class PolynomeNewton : public Polynome<T> {
private:
    T   *_xValues;
public:
    PolynomeNewton(long degre, T *coeff = NULL, T *xValues = NULL);
    ~PolynomeNewton();

    void    setXvalue(long i, T valeur);
    T       getXvalue(long i) const;

    T evalue(T x);
};

template <typename T> PolynomeNewton<T>::PolynomeNewton(long degre, T *coeff, T *xValues) : Polynome<T>(degre, coeff), _xValues(new T[degre]) {
    // si tableau de x en paramètre, on copie le tableau
    if (xValues != NULL)
    {
        for (long i = 0; i < degre; i++)
            _xValues[i] = xValues[i];
    }
}

template <typename T> PolynomeNewton<T>::~PolynomeNewton() {
    delete [] _xValues;
}

// affecte le coefficient d'indice i
template <typename T> void PolynomeNewton<T>::setXvalue(long i, T valeur) {
    assert(i < this->getDegre());
    _xValues[i] = valeur;
}

// retourne le coefficient d'indice i
template <typename T> T PolynomeNewton<T>::getXvalue(long i) const {
    assert(i < this->getDegre());
    return _xValues[i];
}


// évaluation du polynôme de Newton en x ( surcharge de la méthode Polynome<T>::evalue(...) )
template <typename T> T PolynomeNewton<T>::evalue(T x)
{
    // À COMPLÉTER
}



#endif // POLYNOMENEWTON_H_INCLUDED
