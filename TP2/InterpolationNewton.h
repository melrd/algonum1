#ifndef INTERPOLATIONNEWTON_H_INCLUDED
#define INTERPOLATIONNEWTON_H_INCLUDED


#include <iostream>
using namespace std;

#include "PolynomeNewton.h"

template <typename T> class InterpolationNewton {
private:
    T       *_xData, *_yData, **_calcul;
    long    _size;
public:
    InterpolationNewton(long size);
    ~InterpolationNewton();

    void setX(long i, T x);
    void setY(long i, T y);
    void setXY(long i, T x, T y);

    T getX(long i) const;
    T getY(long i) const;

    void calculeSolution();

  //  PolynomeNewton<T>  *solution;
};

template <typename T> InterpolationNewton<T>::InterpolationNewton(long size) : _size(size), _xData(new T[size]), _yData(new T[size]), solution(NULL){
}

template <typename T> InterpolationNewton<T>::~InterpolationNewton() {
    delete[] _xData;
    delete[] _yData;
}

// affecte le coefficient X d'indice i
template <typename T> void InterpolationNewton<T>::setX(long i, T x) {
    assert(i < _size);
    _xData[i] = x;
}

// retourne le coefficient X d'indice i
template <typename T> T InterpolationNewton<T>::getX(long i) const {
    assert(i < _size);
    return _xData[i];
}

// affecte le coefficient Y d'indice i
template <typename T> void InterpolationNewton<T>::setY(long i, T y) {
    assert(i < _size);
    _yData[i] = y;
}

// retourne le coefficient Y d'indice i
template <typename T> T InterpolationNewton<T>::getY(long i) const {
    assert(i < _size);
    return _yData[i];
}

// affecte les coefficient X et Y d'indice i
template <typename T> void InterpolationNewton<T>::setXY(long i, T x, T y) {
    assert(i < _size);
    _xData[i] = x;
    _yData[i] = y;
}

template <typename T> void InterpolationNewton<T>::calculeSolution()
{
    // on supprime la solution calculée précédemment si besoin
    delete solution;
    bool positif = false;
    int coef = 0, j = 0, val = 0;

    for (long i = 0; i < _size ;i++){
        _calcul[coef][i] = _yData[i];
    }

    coef++;

    while(!positif) do{
            for(long j = 0; j < _size; j++){
                _calcul[coef][j] = (_calcul[coef-1][j]-_calcul[coef-1][coef])/(getX(j) - getX(coef));
            }
        calculY(coef);

        for (long k = 0; k < _size; k++){
            if(_calcul[coef][k] == 0)
                j++;
        }

        if (j == _size)
            positif = true;
        else{
            j = 0;
            coef++;
        }
    }

    cout << "Le polynome est : " << endl;
    for (float m = 0; m < coef-1; m++){
        if(_calcul[m][val] !=  0){
            cout<< _calcul[m][val] << "* x ^" << m;
        }
        val ++;
    }
}

#endif // INTERPOLATIONNEWTON_H_INCLUDED
