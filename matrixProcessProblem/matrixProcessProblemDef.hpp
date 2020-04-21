/*
  matrix data process problem
  Tasks:
    * read matrix from a file
    * print matrix
    * the elements from the main diagonal who are prime
    * the paralel values with main diagonal values of order X
    * the paralel values with secondary diagonal values of order X
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

class dataProcessor {

private:
  validationRules __rules__;

  template <class Type> bool isPrime (Type parameter);
  template <class Type> void interchangeValues (Type * parameterOne, Type * parameterTwo);

public:
  dataProcessor () {}

  template <class Type> void readMatrix (char * fileName, matrixType<Type> & MTObject);
  template <class Type> void putsMatrix (matrixType<Type> & MTObject);
  template <class Type> void primeValuesFromMainDiagonal (matrixType<Type> & MTObject);
  template <class Type> void paralelValuesWithMD (matrixType<Type> & MTObject);
  template <class Type> void paralelValuesWithSD (matrixType<Type> & MTObject);
  template <class Type> void matrixTransposition (matrixType<Type> & MTObject);

  virtual ~dataProcessor () {}
};
