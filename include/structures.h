#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <string>

class Individual {
  private :
    int len;
    int *rowValues;

  public :
    Individual(int length) {
      len = length;
      rowValues = new int[length];
    }
    ~Individual() {
      delete [] rowValues;
    }
    int getLen(){
      return len;
    }
    int getRowValue(int col);
    void setRowValue(int col, int val);
    void randomValues();
    std::string toString();
};

class ProbDist {
  private :
    int len, colNum;
    int *matrix;
    ProbDist *prev, *next;
    ProbDist* makeNext(int column, int length, ProbDist *p);
  public :
    ProbDist(int column, int length);
    ~ProbDist();
    void setPrev(ProbDist *p){
        prev = p;
    }
    ProbDist *getPrev(){
        return prev;
    }
    void setNext(ProbDist *p){
        next = p;
    }
    ProbDist *getNext(){
        return next;
    }
    int getValue(int col, int row);
    void setValue(int col, int row, int val);
    int getColumnTotal(int col);
    double getProb(int col, int row);
};

#endif
