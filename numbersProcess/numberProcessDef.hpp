/*
  numbers process
  Tasks:
    * read one dimensional array
    * output one dimensional array
    * remove the duplications and sort every number
    * print out the frequency of every number that appears in array
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

class portData {

public:
  portData () {}

  template <class Type> void portOneDimensionalArray (oneDimensionalArrayType<Type> ODAObjectOne, oneDimensionalArrayType<Type> ODAObjectTwo);

  virtual ~portData () {}
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

class numberProcess {
private:
  validationRules __validations__;

  template <class Type> Type sortAndNormalizeNumber (Type parameter);

public:
  numberProcess () {};

  template <class Type> void normalizeOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference);
  template <class Type> oneDimensionalArrayType<int> frequencyNumbersAppereances (oneDimensionalArrayType<Type> ODARefference);

  virtual ~numberProcess () {}
};
