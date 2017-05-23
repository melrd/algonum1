//  main.cpp
//  Interpolation
//  Created by Nicolas Sicard on 30/04/2016.
//  Copyright © 2016 Efrei. All rights reserved.

#include "InterpolationNewton.h"

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    // EXEMPLE DU COURS
    InterpolationNewton<float> interp(4);
    interp.setXY(0, 0.0, 0.0);
    interp.setXY(1, 2.0, 4.0);
    interp.setXY(2, 4.0, 0.0);
    interp.setXY(3, 6.0, 4.0);

    interp.calculeSolution();

    cout << interp.solution->getCoeff(0) << endl;
    cout << interp.solution->getCoeff(1) << endl;
    cout << interp.solution->getCoeff(2) << endl;
    cout << interp.solution->getCoeff(3) << endl;

    cout << interp.solution->evalue(1.0) << endl;

//    cout << p.evalue(1.0) << endl;

    return 0;
}
