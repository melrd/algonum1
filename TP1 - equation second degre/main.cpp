#include <iostream>
#include "equ.h"

using namespace std;

int main()
{
    cout << "----------------------- Simple precision ----------------------- " << endl;
    equation<float> equ(1.E-8,0.08,1.E-8);  // 10^-8 = 1.E-8
    cout << "----------------------- Methode naive ----------------------- " << endl;
    equ.naiveSolve();
    cout << equ <<endl ;
    cout << "----------------------- Methode maligne ----------------------- " << endl;
    equ.cleverSolve();
    cout << equ <<endl ;


    cout << "----------------------- Double precision ----------------------- " << endl;
    equation<double> equ2(1.E-8,0.08,1.E-8);  // 10^-8 = 1.E-8
    cout << "----------------------- Methode naive ----------------------- " << endl;
    equ2.naiveSolve();
    cout << equ2 <<endl ;
    cout << "----------------------- Methode maligne ----------------------- " << endl;
    equ2.cleverSolve();
    cout << equ2 <<endl ;
    return 0;
}
/*
 l8 : crée objet equation en 32 bit
  méthode
 puis iEEE757 : objet en double
 e objet avec meme paramétrage
 comparer les affichages
*/
