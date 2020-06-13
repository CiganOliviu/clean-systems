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

class portData {

public:
  portData () {}

  template <class Type> void portOneDimensionalArray (oneDimensionalArrayType<Type> ODAObjectOne, oneDimensionalArrayType<Type> ODAObjectTwo);

  virtual ~portData () {}
};


class inputOutputSystem {
private:
  validationRules __validations__;

public:
  inputOutputSystem () {}

  void readOneDimensionalArray (oneDimensionalArrayType<char> dataWorkFlow);
  void outputOneDimensionalArray (oneDimensionalArrayType<char> dataWorkFlow);

  virtual ~inputOutputSystem () {}
};

class stringWorkFlow {
private:
  validationRules __validations__;

  int convertCharToInt (char character);

  bool isOdd (int number);
  bool isEven (int number);

public:
  stringWorkFlow () {}

  oneDimensionalArrayType<char> decodeWord (oneDimensionalArrayType<char> dataWorkFlowOne, oneDimensionalArrayType<char> dataWorkFlowTwo);

  virtual ~stringWorkFlow () {}
};