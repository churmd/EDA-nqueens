#ifndef STRUCTURE_H
#define STRUCTURE_H

//Forward declare
class string;

/**
  Purpose: An Individual represents a single solution to the N-Queens problem, with each index in the rowValues array representing a column and the values stored are the corresponding rows.
  Example: [1,3,0,2]
  Table: Col | 0 1 2 3
         Row | 1 3 0 2
  Coords : (0,1),(1,3),(2,0),(3,2)
  Visually:
     -> X
   | - - Q -
   v Q - - -
   Y - - - Q
     - Q - -
*/
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
    std::string showBoard();
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
