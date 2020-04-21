/*
  ordered sequences
  Tasks:
    * read one dimensional array
    * print one dimensional array
    * get the ordered sequences from the array
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

class objectsWorkFlow {
private:
  validationRules __validations__;

public:
  objectsWorkFlow () {}

  template <class Type> void portData (oneDimensionalArrayType<Type> ODARefferenceOne, oneDimensionalArrayType<Type> ODARefferenceTwo);

  virtual ~objectsWorkFlow () {}
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

class orderedSequencesWorkFlow {
private:
  validationRules __validations__;

public:
 orderedSequencesWorkFlow () {}

 template <class Type> oneDimensionalArrayType<Type> getOrderedSequenceInOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference);

  virtual ~orderedSequencesWorkFlow () {}
};
