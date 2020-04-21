/*
  Tasks:
    * Get the center values of the matrix
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

class validationRules {

public:
  validationRules () {}

  template <class Type> bool isNegative (Type parameter);
  template <class Type> bool isZero (Type parameter);

  virtual ~validationRules () {}
};

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

class inputOutputOperations {
private:
  validationRules __validations__;

public:
  inputOutputOperations () {}

  template <class Type> void outputMatrix (matrixType<Type> & MTObject);

  virtual ~inputOutputOperations () {}
};

class dataProcessor {
private:
  validationRules __rules__;

  bool isPrime (int number);
  int the_N_primeValue (int number);
  bool isOdd (int number);
  bool isEven (int number);
  template <class Type> void getValuesOddMatrix (matrixType<Type> MTObject);
  template <class Type> void getValuesEvenMatrix (matrixType<Type> MTObject);

public:
  dataProcessor () {}

  template <class Type> void generateMatrix (matrixType<Type> & MTObject);
  template <class Type> void processSpecificMatrix (matrixType<Type> MTObject);

  virtual ~dataProcessor () {}
};
