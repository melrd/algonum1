#ifndef POLYNOME_H_INCLUDED
#define POLYNOME_H_INCLUDED

#include <stdio.h>
#include <assert.h>
#include <math.h>

template <typename T> class Polynome {
protected:
    T       *_coeff;
    long    _degre;
public:
    Polynome(long degre, T *coeff = NULL);
    ~Polynome();

    void    setCoeff(long i, T valeur);
    T       getCoeff(long i) const;

    long    getDegre() const;

    T evalue(T x);
    T evalueHorner(T x);
};

template <typename T> Polynome<T>::Polynome(long degre, T *coeff) : _degre(degre), _coeff(new T[degre]) {
    // si tableau de coefficients en paramètre, on copie le tableau
    if (coeff != NULL)
    {
        for (long i = 0; i < _degre; i++)
            _coeff[i] = coeff[i];
    }
}

template <typename T> Polynome<T>::~Polynome() {
    delete[] _coeff;
}

// affecte le coefficient d'indice i
template <typename T> void Polynome<T>::setCoeff(long i, T valeur){
    assert(i < _degre);
    _coeff[i] = valeur;
}

// retourne le coefficient d'indice i
template <typename T> T Polynome<T>::getCoeff(long i) const{
    assert(i < _degre);
    return _coeff[i];
}

template <typename T> long Polynome<T>::getDegre() const{
    return _degre;
}


// évaluation du polynôme en x
template <typename T> T Polynome<T>::evalue(T x){
    T   y = T(_coeff[0]);
    for (long i=1; i < _degre; i++)
    {
        y += _coeff[i]*pow(double(x),double(i));
    }
    return y;
}

template <typename T> T Polynome<T>::evalueHorner(T x){
    // évaluation rapide par la méthode de Horner : https://fr.wikipedia.org/wiki/Méthode_de_Ruffini-Horner
    T   y = T(_coeff[0]);

    float result =

    /*coef *x ^degre+coef-1
*/
    return y;
}



#endif // POLYNOME_H_INCLUDED

