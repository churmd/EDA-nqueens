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
