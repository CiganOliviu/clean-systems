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

  template <class Type> void readFileOneDimensionalArray (char * fileName, oneDimensionalArrayType<Type> ODARefference);
  template <class Type> void outputOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference);

  virtual ~inputOutputOperations () {}
};

class mathematicSupport {
private:
  validationRules __validations__;

public:
  
  mathematicSupport () {}

  bool isPrime (int number);
  int returnSumOfDigits (int number);
  template <class Type> void interchangeValues (Type * parameterOne, Type * parameterTwo);
  template <class Type> int findPositionToInsertInSortedArray (oneDimensionalArrayType<Type> ODARefference, Type valueToSearchFor);

  virtual ~mathematicSupport () {}
};

class arrayWorkFlow : public mathematicSupport {
private:
  validationRules __validations__;
  
public:
  arrayWorkFlow () {}

  template <class Type> void outputPrimeNumbersFromArray (oneDimensionalArrayType<Type> ODARefference);
  template <class Type> void deletePrimeNumbersFromArray (oneDimensionalArrayType<Type> ODARefference);
  template <class Type> void sortByBubbleSort (oneDimensionalArrayType<Type> ODARefference);
  template <class Type> void replaceDoubledValuesFromODAByDigitsSum (oneDimensionalArrayType<Type> ODARefference);

  virtual ~arrayWorkFlow () {}
};