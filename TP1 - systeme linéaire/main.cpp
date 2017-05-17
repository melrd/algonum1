#include <iostream>
#include "fraction.h"
#include "systeme.h"
#include "systeme.tpp.h"

using namespace std;

int main()
{
    Systeme<double> sys;

    cin >> sys;

    cout << sys;

    sys.triangGaussPivotPartiel();
    sys.calculeResultats();

    cout << sys;
}
