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

class portData {
private:
  validationRules __rules__;

public:
  portData () {};

  template <class Type> void portMatrices (matrixType<Type> & matrixObjectOne, matrixType<Type> matrixObjectTwo);

  virtual ~portData () {}
};

class inputOutputOperations {
private:
  validationRules __rules__;

public:
  inputOutputOperations () {}

  template <class Type> void readMatrix (char * fileName, matrixType<Type> & MTObject);
  template <class Type> void putsMatrix (matrixType<Type> & MTObject);

  virtual ~inputOutputOperations () {}
};

class matricesCombinerBasedOnConditions {
private:
  validationRules __rules__;

  template <class Type> Type getMinOfTwoNumbers (Type parameterOne, Type parameterTwo);
  
public:
  matricesCombinerBasedOnConditions () {}

  template <class Type> matrixType<Type> combineMatrices (matrixType<Type> MTObjectOne, matrixType<Type> MTObjectTwo);

  virtual ~matricesCombinerBasedOnConditions () {}
};
