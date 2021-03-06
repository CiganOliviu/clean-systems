/*
  Sort in parts one dimensional array
  Tasks:
    * read one dimensional array from a file
    * print one dimensional array with the new values
    * sort the prime values to the left and the rest to the right
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

class oneDimensionalArrayProcesses {
private:
  validationRules __validations__;

  template <class Type> inline void interchangeValues (Type * parameterOne, Type * parameterTwo);
  bool isPrime (int number);

public:
  oneDimensionalArrayProcesses () {}

  template <class Type> void sortPrimeValuesFromOneDimensionalArray (oneDimensionalArrayType<Type> ODAObject);
  template <class Type> void sortNonePrimeValuesFromOneDimensionalArray (oneDimensionalArrayType<Type> ODAObject);

  virtual ~oneDimensionalArrayProcesses () {}
};
