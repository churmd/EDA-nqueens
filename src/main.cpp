#include <iostream>
#include <list>
#include <string>

using namespace std;

#include "structures.h"
#include "edaAlgo.h"

int main()
{
    cout << "Hello world!" << endl;
    cout << "Hi!" << endl;
    int n;
    cin >> n;
    cout << "You entered: " << n << endl;
    Individual *i = new Individual(4);
    i->randomValues();
    cout << "Length: " << i->getLen() << endl;
    cout << "Row value 0 = " << i->getRowValue(0) << endl;
    cout << "Row value 1 = " << i->getRowValue(1) << endl;
    cout << "Row value 2 = " << i->getRowValue(2) << endl;
    cout << "Row value 3 = " << i->getRowValue(3) << endl;

    ProbDist *pd = new ProbDist(0, 4);
    pd->setValue(1,1,3);
    int a = pd->getValue(1,1);
    cout << a << endl;

    Individual *best = edaLoop(6, 50000);
    cout << best->toString() << endl;
    cout << fitness(best) << endl;

    return 0;
}
