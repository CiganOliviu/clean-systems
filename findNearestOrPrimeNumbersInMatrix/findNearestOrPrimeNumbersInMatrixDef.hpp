/*
nearest or fibonacci problem problem
Tasks:
  * determine if a number is prime, if it is return the number else return the nearest prime number
*/

#include <chrono>
#include <fstream>
#include <iostream>
#include <stdlib.h>

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

  template <class Type> void readMatrix (char * fileName, matrixType<Type> & MTObject);
  template <class Type> void putsMatrix (matrixType<Type> & MTObject);

  virtual ~inputOutputOperations () {}
};

class matrixWorkFlow {
private:
  validationRules __validations__;

  int returnPrimeNumber (int number);
  int minimumDifference (int argOne, int argTwo, int differenceTermen);
  int returnNearestOrPrimeNumber (int number);

public:
  matrixWorkFlow () {}

  template <class Type> void primeOrClosestPrimeValuesMatrix(matrixType<Type> & MTObject);

  virtual ~matrixWorkFlow () {}
};
