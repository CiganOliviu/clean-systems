/*
  min max OOP problem
  Tasks:
    * read one dimensional array
    * output the one dimensional array with the new values
    * get the maximmum value
    * get the minimum value
    * interchange the two values in the one dimensional array
*/

#include <chrono>
#include <fstream>
#include <iostream>

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

  template <class Type> void readOneDimensionalArray (char * fileName, oneDimensionalArrayType<Type> ODARefference);
  template <class Type> void outputOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference);

  virtual ~inputOutputOperations () {}
};

class minMaxWorkFlow {
private:
  validationRules __validations__;

public:
  minMaxWorkFlow () {}

  template <class Type> Type maximOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference);
  template <class Type> Type minimOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference);
  template <class Type> void interchangeValues (Type * parameterOne, Type * parameterTwo);
  template <class Type> void interchangeMaxMin (oneDimensionalArrayType<Type> ODARefference);

  virtual ~minMaxWorkFlow () {}
};
