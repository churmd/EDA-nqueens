#include <iostream>
#include <list>
#include <string>

using namespace std;

#include "structures.h"
#include "edaAlgo.h"

int main(int argc, char const *argv[]) {
  int exitStat = 0;

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
    exitStat = 1;
    cout << e.what() << endl;
  }


  return exitStat;
}
