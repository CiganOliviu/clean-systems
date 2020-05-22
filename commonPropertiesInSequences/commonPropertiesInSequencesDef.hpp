/*
  one dimensional array data process problem
  Tasks:
  * Count the maximum lenth of a sequence who is divisible with a specific number and
  print how many of this sequences are present
*/

#include <chrono>
#include <fstream>
#include <iostream>

#ifndef STD_LENGTH
#define STD_LENGTH 100000
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

class inputOutputOperations {
private:
  validationRules __validations__;

public:
  inputOutputOperations () {}

  template <class Type> void readOneDimensionalArray (char * fileName, oneDimensionalArrayType<Type> ODARefference);
  template <class Type> void outputOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference);

  virtual ~inputOutputOperations () {}
};

class processData {
private:
  validationRules __validations__;

  template <class Type> Type returnMaximumValue (Type numberOne, Type numberTwo);

public:
  processData () {}

  template <class Type> int getMaximumLengthOfSequence (oneDimensionalArrayType<Type> ODARefference, Type divisor);
  template <class Type> int getNumberOfDivisors (oneDimensionalArrayType<Type> ODARefference, Type divisor);

  virtual ~processData () {}
};
