/*
  Tasks:
    * return the maximum odd digit from a number
*/

#include <chrono>
#include <fstream>
#include <iostream>

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
  template <class Type> bool isZeroOrNegative (Type parameter);

  virtual ~validationRules () {}
};

class maxDigitProcessor {
private:
  validationRules __validations__;

  bool isOdd (int number);
  int returnMaxValueFrom (int parameterOne, int parameterTwo);

public:
  maxDigitProcessor () {}

  int returnMaxOddDigitFromANumber (int number);

  virtual ~maxDigitProcessor () {}   
};
