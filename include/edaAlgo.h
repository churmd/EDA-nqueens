#ifndef EDAALGO_H
#define EDAALGO_H value

#include <list>

#include "structures.h"

std::list<Individual *> *firstGen(int maxPop, int indLen);

ProbDist *makeProbDist(std::list<Individual *> *generation, int tableSize);

std::list<Individual *> *makeNewGen(ProbDist *pd, int boardSize, int popSize);

int fitness(Individual *ind);

void sortGeneration(std::list<Individual *> *gen);

std::list<Individual *> *take(std::list<Individual *> *pop, int stopAt);

Individual *edaLoop(int boardSize, int maxIterations);

#endif
