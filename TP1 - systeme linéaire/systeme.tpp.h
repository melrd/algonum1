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

    for (long cpt = 0; cpt < _size+1; cpt++)
    {
        if (_values[ligpivot][cpt] != 0)
        {
            pivot = _values[ligpivot][cpt];
            coeff =  _values[ligatraiter][cpt] / pivot;
            break;
        }
    }
    for (long cpt = 0; cpt < _size+1; cpt++)
    {
        _values[ligatraiter][cpt] = _values[ligatraiter][cpt] - (_values[ligpivot][cpt] * coeff);

        if ( abs(_values[ligatraiter][cpt]) < 0.000001)
             _values[ligatraiter][cpt] = 0;
    }

    return;
}


template <typename T> void Systeme<T>::echangeLignes(long lig1, long lig2)
{
    T* temp = _values[lig1];

    _values[lig1] = _values[lig2];
    _values [lig2] = temp;

    return;
}

template <typename T> void Systeme<T>::echangeColonnes(long col1, long col2)
{
    T temp;

    for (long ligne = 0; ligne < _size; ligne++)
    {
        temp = _values[ligne][col1];
        _values[ligne][col1] = _values[ligne][col2];
        _values[ligne][col2] = temp;
    }

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

    long indmax =0;

    for (cpt=0; cpt < _size; cpt++)
    {
        indmax =cpt;
        // choix de la ligne de pivotage

        for (long l = cpt; l < _size; l++)
        {
            if (abs(_values[l][cpt]) > abs(_values[indmax][cpt]))
                indmax = l;
        }

        if (indmax != cpt)
            echangeLignes(cpt,indmax); // et hop on echange les lignes

     cout << "apres choix du pivot : " << endl << *this << endl;

     // pivotage effectif

     for(cpt2= cpt+1; cpt2 < _size; cpt2++)
     {
        pivote(cpt, cpt2);
     }
     cout << "apres pivotage de la ligne " << endl << *this;
    }

    return;
}


template <typename T> void Systeme<T>::triangGaussPivotTotal()
{
    long indexmax1 = 0, indexmax2 = 0;

    for (long cpt= 0; cpt < _size; cpt++)
    {
        for(long cpt2 = cpt; cpt < _size; cpt2++)
        {
            indexmax2 = cpt2;
            indexmax1 = cpt;

            for(long k = cpt; k< _size; k++)
            {
                for(long i = k; i< _size; k++)
                {
                    if(abs(_values[indexmax1][indexmax2]) < abs(_values[k]))
                {
                    indexmax1 = k;
                    indexmax2 = i;
                }
            }
        }


    if(indexmax2 != cpt2)
        echangeColonnes(cpt2,indexmax2);
    }

    if(indexmax1 != cpt)
        echangeLignes(cpt,indexmax1);

    cout << "apres choix du pivot " << endl << *this << endl;

    for(long j = cpt+1; j<_size; j++)
        pivote(cpt,j);

    cout << "apres pivot ligne " << endl << endl << *this;
}
    return;
}


template <typename T> void Systeme<T>::iterJacobi()
{
   /*long itr, n;
      n = 0;
    //printf("\n\nEnter relative error and number of iteration ::  \n");

    //scanf("%f%d",&e,&maxit);
    T* x = NULL;
     x = new T[n];

    for(long i=1;i<=n;i++)
    x[i]=i;

    for(itr=1;itr<=_size;itr++)
    {
        long big=0;
        for(long i=1;i<=n;i++)
        {
            long sum=0;
            for(long j=1;j<=n;j++)
             {
               if(i!=j)
               {
                    sum=sum+abs(_values[i][j])*x[j];
               }
              }
            long temp=(abs(_values[i][n+1])-sum)/abs(_values[i][i]);
            long relerror=fabs((x[i]-temp)/temp);

            if(relerror>big)
               big=relerror;
            x[i]=temp;
        }

        cout<<"Converges vers une solution en "<<itr<<" iterations"<<endl;

        for(long i=1;i<=n;i++)
        {
             cout <<x[i]<< endl;
        }

    }*/
}



template <typename T> void Systeme<T>::iterGaussSeidel() // fait a partir de l'algorithme vu en cours
{
    /*<T> oldX, eX;
    float dx;

    do{
        oldX = x;

        for (i=0; i<n; i++)
        {
            float somme = 0.0;

            for (j=1; j<n; j++)
            {
                if (j =! i)
                    somme = somme + A[i][j] * x[j];
            }
            x[i] = (b[i] - somme) / A[i][i];
        }
    }while (dx > epsilon);*/


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
