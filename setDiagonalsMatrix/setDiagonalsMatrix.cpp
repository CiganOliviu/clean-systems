/*
  set diagonals in matrix problem
  Tasks:
    * generate a matrix with diagonals equal with 1 and all other values equal to 2
    * print the matrix
*/

#include <chrono>
#include <fstream>
#include <iostream>
#include <math.h>

#ifndef MATRIX_STD_LENGTH
#define MATRIX_STD_LENGTH 100
#endif

using namespace std::chrono;

class systemException : public std::exception {
private:
  std::string processMessage;

public:
  systemException (std::string errorMessage) : processMessage(errorMessage) {}

  const char * what () const throw ();

  virtual ~systemException () throw () {}
};

const char * systemException::what () const throw () {

  return processMessage.c_str();
}

class validationRules {

public:
  validationRules () {}

  template <class Type> bool isNegative (Type parameter);
  template <class Type> bool isZero (Type parameter);

  virtual ~validationRules () {}
};

template <class Type> bool validationRules::isNegative (Type parameter) {

    if (parameter < 0) return true;

    return false;
}

template <class Type> bool validationRules::isZero (Type parameter) {

    if (parameter == 0) return true;

    return false;
}

template <class Type> class matrixType {
private:
  int standardSize = 0;

public:
  matrixType () {}

  int line = standardSize;
  int & lineRefference = line;
  int column = standardSize;
  int & columnRefference = column;

  int startLinePoint = standardSize;
  int endLinePoint = standardSize;
  int startColumnPoint = standardSize;
  int endColumnPoint = standardSize;

  Type matrix[MATRIX_STD_LENGTH][MATRIX_STD_LENGTH];

  virtual ~matrixType () {}
};

class matrixProcessor {
private:
  validationRules __rules__;

public:
  matrixProcessor () {}

  template <class Type> void putsMatrix (matrixType<Type> MTObject);
  template <class Type> void generateMatrix (matrixType<Type> & MTObject);

  virtual ~matrixProcessor () {}
};

template <class Type> void matrixProcessor::putsMatrix (matrixType<Type> MTObject) {

  if (__rules__.isZero(MTObject.lineRefference) || __rules__.isZero(MTObject.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__rules__.isNegative(MTObject.lineRefference) || __rules__.isNegative(MTObject.columnRefference)) throw systemException ("Unable to process with negative line or column");

  for (size_t iterator = MTObject.startLinePoint; iterator < MTObject.lineRefference + MTObject.endLinePoint; iterator++) {
    for (size_t jiterator = MTObject.startColumnPoint; jiterator < MTObject.columnRefference + MTObject.endColumnPoint; jiterator++)
      std::cout << MTObject.matrix[iterator][jiterator] << " ";
    std::cout << '\n';
  }
}

template <class Type> void matrixProcessor::generateMatrix (matrixType<Type> & MTObject) {

  MTObject.columnRefference = MTObject.lineRefference;

  if (__rules__.isZero(MTObject.lineRefference) || __rules__.isZero(MTObject.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__rules__.isNegative(MTObject.lineRefference) || __rules__.isNegative(MTObject.columnRefference)) throw systemException ("Unable to process with negative line or column");

  for (size_t iterator = MTObject.startLinePoint; iterator < MTObject.lineRefference + MTObject.endLinePoint; iterator++)
    for (size_t jiterator = MTObject.startColumnPoint; jiterator < MTObject.columnRefference + MTObject.endColumnPoint; jiterator++)
       if (iterator + 1 == jiterator + 1)
          MTObject.matrix[iterator][jiterator] = 1;
       else if ((iterator + jiterator + 1) == MTObject.lineRefference)
          MTObject.matrix[iterator][jiterator] = 1;
       else
          MTObject.matrix[iterator][jiterator] = 2;
}

int main(int argc, char const *argv[]) {

  matrixProcessor processor;
  matrixType<int> matrix;

  std::cin >> matrix.lineRefference;

  processor.generateMatrix (matrix);
  processor.putsMatrix (matrix);

  return 0;
}
