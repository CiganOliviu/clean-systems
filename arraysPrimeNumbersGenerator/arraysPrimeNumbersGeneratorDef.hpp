/*
  arrays prime numbers generator
  Task:
    * generate one dimensional array with first n prime values
    * output one dimensional array
    * generate matrix with first n prime values
    * output matrix
*/

#include <chrono>
#include <fstream>
#include <iostream>
#include <math.h>

#ifndef STD_LENGTH
#define STD_LENGTH 1000
#endif

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

template <class Type> class oneDimensionalArrayType {
private:
  int standardSize = 0;

public:
  oneDimensionalArrayType () {}

  int & length = standardSize;
  int startPoint = standardSize;
  int endPoint = standardSize;

  Type * oneDimensionalArray = new Type[STD_LENGTH];

  virtual ~oneDimensionalArrayType () {}
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

class portData {

public:
  portData () {}

  template <class Type> void portOneDimensionalArray (oneDimensionalArrayType<Type> ODAObjectOne, oneDimensionalArrayType<Type> ODAObjectTwo);
  template <class Type> void portMatrix(matrixType<Type> & matrixObjectOne, matrixType<Type> matrixObjectTwo);

  virtual ~portData () {}
};

class inputOutputOperations {
private:
  validationRules __validations__;

public:
  inputOutputOperations () {}

  template <class Type> void outputOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference);
  template <class Type> void outputMatrix (matrixType<Type> & MTObject);

  virtual ~inputOutputOperations () {}
};

class arraysGenerator {
private:
  validationRules __rules__;

  bool isPrime (int number);

public:
  arraysGenerator () {}

  template <class Type> matrixType<Type> generatePrimeMatrix (int stopLimitGenerator);

  template <class Type> oneDimensionalArrayType<Type> generatePrimeOneDimensionalArray (int stopLimitGenerator);

  virtual ~arraysGenerator () {}
};
