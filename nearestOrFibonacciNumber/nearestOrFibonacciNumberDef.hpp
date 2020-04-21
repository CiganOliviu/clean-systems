/*
nearest or fibonacci problem problem
Tasks:
  * determine if a number is fibonacci, if it is return the number else return the nearest fibonacci number
*/

#include <chrono>
#include <iostream>
#include <stdlib.h>

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

class fibonacciWorkFlow {
private:
  validationRules __validations__;

  int minimumDifference (int argOne, int argTwo, int differenceTermen);
  int returnFibonacciNumber (int numberIndex);

public:
  fibonacciWorkFlow () {}

  int returnNearestOrFiboNumber (int number);

  virtual ~fibonacciWorkFlow () {}
};
