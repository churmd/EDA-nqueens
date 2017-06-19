#include "edaAlgo.h"

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
