#include <iostream>
#include <list>
#include <string>

using namespace std;

#include "structures.h"
#include "edaAlgo.h"
/*
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

    Individual *best = edaLoop(5, 50000, 1);
    cout << best->toString() << endl;
    cout << fitness(best) << endl;

    return 0;
}
*/

int main(int argc, char const *argv[]) {
  int queenNum = 1;
  int maxIter = 1000;
  int iterModifier = 1;
  try {
    if(argc < 2){
        cout << "Usage: ./nqueens <number of queens> <maximum number of iterations> <iteration increment>" << endl;
        cout << "Set iteration increment to 0 for an unlimited number of iterations or 1 to cap iterations at the specified maximum value." << endl;
        cout << endl;
        cout << "No arguements passed, defualt values used." << endl;
        cout << "Number of Queens: " << queenNum << endl;
        cout << "Maximum number of iterations: " << maxIter << endl;
        cout << "Iteration increment value: " << iterModifier << endl;
    }
    if(argc >= 2){
      queenNum = std::stoi(argv[1]);
    }
    if(argc >= 3){
      maxIter = std::stoi(argv[2]);
    }
    if(argc >= 4){
      iterModifier = std::stoi(argv[3]);
    }

    Individual *best = edaLoop(queenNum, maxIter, iterModifier);
    cout << "Best solution found: " << best->toString() << endl;
    cout << best->showBoard() << endl;

    delete best;
  } catch (const std::exception& e) {
    cout << e.what() << endl;
  }


  return 0;
}
