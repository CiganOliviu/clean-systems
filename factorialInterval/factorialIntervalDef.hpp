#include <chrono>
#include <fstream>
#include <iostream>
#include <math.h>

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
  template <class Type> bool areEqual (Type parameterOne, Type parameterTwo);

  virtual ~validationRules () {}
};

class limits {

public:
  int minimLimit = 0;
  int maximLimit = 0;
};

class inputOutputOperations {

public:
  inputOutputOperations () {}

  int readNumber ();
  void outputNumber (int number);

  virtual ~inputOutputOperations () {}
};

class factorialInterval {
private:
  validationRules __validations__;
  
  int returnFactorialValue (int numar);

public:
  factorialInterval () {}

  limits returnFactorialInterval (int number);
  int returnIntervalDifference (limits interval);

  virtual ~factorialInterval () {}
};