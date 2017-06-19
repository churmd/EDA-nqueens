#ifndef STRUCTURE_H
#define STRUCTURE_H

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
      delete rowValues;
    }
    int getLen(){
      return len;
    }
    int getRowValue(int col);
    void setRowValue(int col, int val);
    void randomValues();
    string toString();
}

#endif
