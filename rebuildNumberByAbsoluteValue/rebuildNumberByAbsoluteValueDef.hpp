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

class numbersProcessor {
private:

  template <class Type> Type returnAbsoluteValue (Type parameterOne, Type parameterTwo);
  template <class Type> Type reverseNumber (Type number, validationRules __validations__);

public:
  numbersProcessor () {}

  template <class Type> Type constructNumber (Type number, validationRules __validations__);

  virtual ~numbersProcessor () {}
};
