/*
  Sort char array
  Tasks:
    * Delete floating point numbers from a char array
*/

#include <chrono>
#include <fstream>
#include <iostream>
#include <string.h>

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

  bool isNegative (char parameter[]);
  bool isZero (char parameter[]);

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

class inputOutputSystem {
private:
  validationRules __validations__;

public:
  inputOutputSystem () {}
  
  void readOneDimensionalArray (oneDimensionalArrayType<char> ODAObject);
  void outputOneDimensionalArray (oneDimensionalArrayType<char> ODAObject);

  virtual ~inputOutputSystem () {}
};

class removerProcessor {
private:
  validationRules __validations__;

public:
  removerProcessor () {}

  void RemoveFloatingPointNumbersFromWordsSequence (oneDimensionalArrayType<char> ODAObject);

  virtual ~removerProcessor () {}
};