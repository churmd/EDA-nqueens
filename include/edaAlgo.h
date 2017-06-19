#ifndef EDAALGO_H
#define EDAALGO_H value

#include <list>
#include <random>

#include "structures.h"

std::list<Individual *> *firstGen(int maxPop, int indLen);

ProbDist *makeProbDist(std::list<Individual *> *generation, int tableSize);

std::list<Individual *> *makeNewGen(ProbDist *pd, int boardSize, int popSize);

#endif
