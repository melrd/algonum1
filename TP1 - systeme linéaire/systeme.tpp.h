#include <iostream>
#include <cmath>

// template method implementation
// not to be compiled from a separate cpp file !

using namespace std;

template <typename T> Systeme<T>::Systeme()
{
        _values = NULL;
        _solution = NULL;
        _permut = NULL;
        _size = 0;
}

template <typename T> void Systeme<T>::alloueSysteme(long size)
{
    if (size > 0)
    {
        _size = size;
        _solution = new T[_size];
        _permut = new long[_size];

        _values = new T*[_size];
        for (long cpt = 0; cpt < _size;cpt++)
        {
            _values[cpt] = new T[_size+1];      // stockage du second membre
            _solution[cpt] = (T)0;
            _permut[cpt] = cpt;
        }
    }
}


template <typename T> Systeme<T>::~Systeme()
{
    if (_permut != NULL)
    {
        delete[] _permut;
    }

    if (_solution != NULL)
    {
        delete[] _solution;
    }

    if (_values != NULL)
    {
        for (long cpt=0; cpt < _size; cpt++)
        {
            delete[] _values[cpt];
        }

        delete[] _values;
    }
}

template <typename U> ostream& operator<<(ostream& os, const Systeme<U> &s)
{

    for (long lig = 0; lig < s._size; lig++)
    {
        os << "|";

        for (long col= 0; col < s._size; col++)
        {
            os << '\t' << s._values[lig][col];
        }

        os << "|" << '\t' << s._values[lig][s._size] << "|" << endl;
    }

    for(long col=0; col < s._size; col++)
    {
        os << "  x" << col+1 << " = " << s._solution[col];
    }

    os << endl;

    return os;
}

template <typename U> istream& operator>>(istream &is, Systeme<U>& s)
{
    long size;

    is >> size;

    s.alloueSysteme(size);

    for (long lig = 0; lig < s._size; lig++)
    {
        for (long col=0; col < s._size+1; col++)
        {
            is >> s._values[lig][col];
        }
    }

    return is;
}

template <typename T> void Systeme<T>::pivote(long ligpivot, long ligatraiter)
{
    T pivot, coeff;

    pivot = /* a vous de jouer */
    coeff = /* a vous de jouer */

    for (long cpt = 0; cpt < _size+1; cpt++)
    {
        _values[ligatraiter][cpt] = /* a vous de jouer */
    }

    return;
}


template <typename T> void Systeme<T>::echangeLignes(long lig1, long lig2)
{
    T temp;

    /* a vous de jouer */

    return;
}

template <typename T> void Systeme<T>::echangeColonnes(long col1, long col2)
{
    T temp;

    /* a vous de jouer */

    return;
}


template <typename T> void Systeme<T>::triangGauss()
{
    for (long cpt = 0; cpt < _size; cpt++)
    {
        for (long cpt2 = cpt+1; cpt2 < _size; cpt2++)
        {
            /* a vous de jouer */
        }
    }

    return;
}


template <typename T> void Systeme<T>::triangGaussPivotPartiel()
{
    long cpt, cpt2;

    long indmax;

    for (cpt=0; cpt < _size; cpt++)
    {
        // choix de la ligne de pivotage

        /* a vous de jouer */

     echangeLignes(cpt,indmax); // et hop on echange les lignes

     cout << "apres choix du pivot : " << endl << *this << endl;

     // pivotage effectif

     for(cpt2= cpt+1; cpt2 < _size; cpt2++)
     {
        /* a vous de jouer */
     }
     cout << "apres pivotage de la ligne " << endl << *this;

    }

    return;
}


template <typename T> void Systeme<T>::triangGaussPivotTotal()
{

}


template <typename T> void Systeme<T>::iterJacobi()
{

}


template <typename T> void Systeme<T>::iterGaussSeidel()
{

}

template <typename T> void Systeme<T>::calculeResultats()
{
    long colonneB = _size;
    long cpt, cpt2;

    for (cpt=_size-1; cpt >=0; cpt--)
    {
        _solution[cpt] = _values[cpt][colonneB];

        for (cpt2=cpt+1; cpt2 < _size; cpt2++)
        {
            _solution[cpt] = _solution[cpt]-(_values[cpt][cpt2]*_solution[cpt2]);
        }

        _solution[cpt] = _solution[cpt] / _values[cpt][cpt];
    }

    return;
}
