/*
  one dimensional array data process problem
  Tasks:
    * read one dimensional array from a file
    * print one dimensional array with the new values
    * save the prime values from the array and print them
    * save the non prime values from the array and print them
    * sort the prime values and print them
    * sort the non prime values and print them
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

  template <class Type> inline void interchangeValues (Type * parameterOne, Type * parameterTwo);
  template <class Type> bool isPrime (Type parameter);

public:
  processData () {}

  template <class Type> oneDimensionalArrayType<Type> getPrimeValueOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference);
  template <class Type> oneDimensionalArrayType<Type> getNonPrimeValueOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference);
  template <class Type> void bubbleSort (oneDimensionalArrayType<Type> ODARefference);

  virtual ~processData () {}
};

class objectsWorkFlow {
private:
  validationRules __validations__;

public:
  objectsWorkFlow () {}

  template <class Type> void portData (oneDimensionalArrayType<Type> ODARefferenceOne, oneDimensionalArrayType<Type> ODARefferenceTwo);

  virtual ~objectsWorkFlow () {}
};
