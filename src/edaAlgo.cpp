#include <stdexcept>
#include <random>

#include "edaAlgo.h"

void deleteLists(std::list<Individual *> *l){
    for(Individual *ind : *l){
        delete ind;
    }
    delete l;
}

std::list<Individual *> *firstGen(int maxPop, int indLen){
    std::list<Individual *> *l = new std::list<Individual *>();
    for(int i = 0; i < maxPop; i++){
        Individual *ind = new Individual(indLen);
        ind->randomValues();
        l->push_front(ind);
    }
    return l;
}

ProbDist *makeProbDist(std::list<Individual *> *generation, int tableSize){
    ProbDist *pd = new ProbDist(0, tableSize);
    for(Individual *ind : *generation){
        for(int col = 0; col < tableSize; col++){
            int row = ind->getRowValue(col);
            pd->setValue(col, row, pd->getValue(col, row) + 1);
        }
    }
    return pd;
}

std::list<Individual *> *makeNewGen(ProbDist *pd, int boardSize, int popSize){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0, 1);

    std::list<Individual *> *l = new std::list<Individual *>();
    for(int i = 0; i < popSize; i++){
        Individual *ind = new Individual(boardSize);
        for(int col = 0; col < boardSize; col++){
            double p = dist(gen);
            for(int row = 0; row < boardSize; row++){
                if(p <= pd->getProb(col, row)){
                    ind->setRowValue(col, row);
                    break;
                }
            }
        }
        l->push_back(ind);
    }
    return l;
}

int fitness(Individual *ind){
    int attacks = 0;
    for(int i = 0; i < ind->getLen(); i++){
         for(int j = 0; j < ind->getLen(); j++){
            //same queen, do nothing
            if(i == j){
                continue;
            }
            //same row attacks
            if(ind->getRowValue(i) == ind->getRowValue(j)){
                attacks++;
            }
            // diagonal attacks
            if(abs(i - j) == abs(ind->getRowValue(i) - ind->getRowValue(j))){
                attacks++;
            }
        }
    }
    return attacks;
}

void sortGeneration(std::list<Individual *> *gen){
    gen->sort([](Individual *i1, Individual *i2){return fitness(i1) < fitness(i2);});
}

std::list<Individual *> *take(std::list<Individual *> *pop, int stopAt){
    if(pop->size() < stopAt){
        throw std::out_of_range("Tried to take more than the size of the list");
    }
    std::list<Individual *> *l = new std::list<Individual *>();
    for(int i = 0; i < stopAt; i++){
        l->push_back(pop->front());
        pop->pop_front();
    }
    return l;
}

Individual *edaLoop(int boardSize, int maxIterations, int iterModifier){
  if(boardSize <= 0){
    throw std::invalid_argument("Board size must be greater then 0");
  } else if(maxIterations < 1){
    throw std::invalid_argument("Maximum number of iterations must be 1 or greater");
  } else {
    int maxPop = 80;
    std::list<Individual *> *population = firstGen(maxPop, boardSize);
    bool stop = false;
    int iter = 0;
    while(!stop){
        sortGeneration(population);

        if(iter == maxIterations || fitness(population->front()) == 0){
            stop = true;
        } else {

            std::list<Individual *> *poptemp = take(population, maxPop/2);
            ProbDist *pd = makeProbDist(poptemp, boardSize);

            deleteLists(population);

            population = makeNewGen(pd, boardSize, maxPop);
            iter = iter + iterModifier;

            deleteLists(poptemp);
            delete pd;
        }
    }
    Individual *best = population->front();
    population->pop_front();
    deleteLists(population);
    return best;
  }
}
