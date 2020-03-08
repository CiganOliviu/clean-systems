/*
  one to zero alternation problem
  Tasks:
    * generate an alternated one zero matrix
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

  bool isEven (int number);

public:
  matrixProcessor () {}

  template <class Type> void putsMatrix (matrixType<Type> MTObject);
  template <class Type> void generateAlternatedMatrix (matrixType<Type> & MTObject);

  virtual ~matrixProcessor () {}
};

bool matrixProcessor::isEven (int number) {

    if (__rules__.isNegative(number)) throw systemException ("Unable to process with negative number");

    if (number % 2 == 0) return true;

    return false;
}

template <class Type> void matrixProcessor::putsMatrix (matrixType<Type> MTObject) {

  if (__rules__.isZero(MTObject.lineRefference) || __rules__.isZero(MTObject.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__rules__.isNegative(MTObject.lineRefference) || __rules__.isNegative(MTObject.columnRefference)) throw systemException ("Unable to process with negative line or column");

  for (size_t iterator = MTObject.startLinePoint; iterator < MTObject.lineRefference + MTObject.endLinePoint; iterator++) {
    for (size_t jiterator = MTObject.startColumnPoint; jiterator < MTObject.columnRefference + MTObject.endColumnPoint; jiterator++)
      std::cout << MTObject.matrix[iterator][jiterator] << " ";
    std::cout << '\n';
  }
}

template <class Type> void matrixProcessor::generateAlternatedMatrix (matrixType<Type> & MTObject) {

  MTObject.columnRefference = MTObject.lineRefference;

  if (__rules__.isZero(MTObject.lineRefference) || __rules__.isZero(MTObject.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__rules__.isNegative(MTObject.lineRefference) || __rules__.isNegative(MTObject.columnRefference)) throw systemException ("Unable to process with negative line or column");

  for (size_t iterator = MTObject.startLinePoint; iterator < MTObject.lineRefference + MTObject.endLinePoint; iterator++)
    for (size_t jiterator = MTObject.startColumnPoint; jiterator < MTObject.columnRefference + MTObject.endColumnPoint; jiterator++) {
       if (isEven(iterator + jiterator)) MTObject.matrix[iterator][jiterator] = 1;
       else MTObject.matrix[iterator][jiterator] = 0;
     }
}

int main(int argc, char const *argv[]) {

  matrixProcessor processor;
  matrixType<int> matrix;

  std::cin >> matrix.lineRefference;

  processor.generateAlternatedMatrix (matrix);
  processor.putsMatrix (matrix);

  return 0;
}
