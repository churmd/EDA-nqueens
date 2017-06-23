/**
  structures.h
  Purpose: Defines classes for the data structures used in the EDA. Specifically, this contains the implementations of the more complex functions.
*/

#include <stdexcept>
#include <random>

#include "structures.h"

int Individual::getRowValue(int col){
  if(col < len && col >= 0){
    return rowValues[col];
  } else {
    throw std::out_of_range("Indexed outside of Individual's length in get");
  }
}

void Individual::setRowValue(int col, int val){
  if(col < len && col >=0){
    rowValues[col] = val;
  } else {
    throw std::out_of_range("Indexed outside of Individual's length int set");
  }
}

void Individual::randomValues(){
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(0, len-1);
  for(int col = 0; col < len; col++){
      rowValues[col] = dist(gen);
  }
}

std::string Individual::toString(){
  std::string s = "|";
  for(int col = 0; col < len; col++){
      s = s + std::to_string(rowValues[col]) + "|";
  }
  return s;
}

std::string Individual::showBoard(){
  std::string board = "";
  for(int row = 0; row < len; row++){
    std::string s = "";
    for(int col = 0; col < len; col++){
      if(getRowValue(col) == row){
        s = s + "Q ";
      } else {
        s = s + "- ";
      }
    }
    board = board + s + "\n" ;
  }
  return board;
}

ProbDist* ProbDist::makeNext(int column, int length, ProbDist *p){
  ProbDist *pd = new ProbDist(column, length);
  pd->setPrev(p);
  return pd;
}

ProbDist::ProbDist(int column, int length){
  prev = nullptr;
  next = nullptr;
  len = length;
  colNum = column;
  matrix = new int[length];

  for(int i = 0; i < length; i++){
    matrix[i] = 1;
  }

  if(column + 1 < length){
    setNext(makeNext(column + 1, length, this));
  }
}
ProbDist::~ProbDist(){
  delete [] matrix;
  if(next){
    delete next;
  }
}

int ProbDist::getValue(int col, int row){
    if(col == colNum){
      if(row < len && row >= 0){
        return matrix[row];
      } else {
          throw std::out_of_range("Indexed outside of row range in ProbDist");
      }
    } else if(next != nullptr){
      return next->getValue(col, row);
    } else {
      throw std::out_of_range("Indexed outside of column range in ProbDist");
    }
}

void ProbDist::setValue(int col, int row, int val){
    if(col == colNum){
      if(row < len && row >= 0){
        matrix[row] = val;
      } else {
          throw std::out_of_range("Indexed outside of row range in ProbDist");
      }
    } else if(next != nullptr){
      return next->setValue(col, row, val);
    } else {
      throw std::out_of_range("Indexed outside of column range in ProbDist");
    }
}

int ProbDist::getColumnTotal(int col){
  if(col == colNum){
    int total = 0;
    for(int row = 0; row < len; row++){
      total = total + matrix[row];
    }
    return total;
  } else if(next != nullptr){
    return next->getColumnTotal(col);
  } else {
    throw std::out_of_range("Indexed outside of column range in ProbDist");
  }
}

double ProbDist::getProb(int col, int row){
  int total = 0;
  while(row >= 0){
    total = total + getValue(col, row);
    row--;
  }
  return ((double) total) / getColumnTotal(col);
}
