/**
    edaAlgo.h
    Purpose: Defines a set of functions that make up the EDA which use the classes from structures.h
*/

#ifndef EDAALGO_H
#define EDAALGO_H value

#include <list>

#include "structures.h"

/**
  Generates a set of Individual's

  @param maxPop The number of Individual's to be created
  @param indLen The size of each Individual, aka the board size/number of queens
  @return A list which contains pointers to the new Individual's
*/
std::list<Individual *> *firstGen(int maxPop, int indLen);


/**
  Creates a probability distribution from the current population

  @param generation A pointer to the list of Individual's that is the current generation
  @param tableSize The size of the board
  @return A ProbDist built from the given generation
*/
ProbDist *makeProbDist(std::list<Individual *> *generation, int tableSize);

/**
  Creates a new generation from a probability distribution

  @param pd The probability distribution to sample from to create the new generation
  @param boardSize The size of the board
  @param popSize The size of the population to be created
  @return A list of Individual's created by sampling from the provided ProbDist
*/
std::list<Individual *> *makeNewGen(ProbDist *pd, int boardSize, int popSize);

/**
  Calculates the fitness of an Individual by seeing how many attacks can be made

  @param ind The Individual to be assessed
  @return The fitness of the Individual (lower is better)
*/
int fitness(Individual *ind);

/**
  Sorts a list of Individual's according to their fitness

  @param gen The generation (list if Individual's) to be sorted
*/
void sortGeneration(std::list<Individual *> *gen);

/**
  Takes the first N Individual's in a list and returns then in a new list

  @param pop The list to take from
  @param stopAt The number of Individual's to take
  @return A new list conataining the first elements of pop
*/
std::list<Individual *> *take(std::list<Individual *> *pop, int stopAt);

/**
  Runs an Estimation of Distribution Algorithm and returns a solution to the N Queens problem or the best one it could find

  @param boardSize The width and height of the board, aka the number of queens
  @param maxIterations The maximum number of times the EDA will be ran before returning the best solution it has found
  @param iterModifier The value that will be added to the iteration counter, so can be set to 0 for infinite runtime
  @return The Individual that is the best solution that has been found
*/
Individual *edaLoop(int boardSize, int maxIterations, int iterModifier);

#endif
