/*
  numbers process
  Tasks:
    * Output the number of divisors who have the same parity
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

class paritySupport {
private:
  validationRules __validations__;

public:
  paritySupport () {}

  bool isOdd (int number);
  bool isEven (int number);

  virtual ~paritySupport () {}
};

class numbersProcessor {
private:
  validationRules __validations__;
  paritySupport __support__;

  int returnNumberOfOddDivisors (int number);
  int returnNumberOfEvenDivisors (int number);

public:
  numbersProcessor () {}

  int returnNumberOfDivisorsOfTheSameParity (int number);

  virtual ~numbersProcessor () {}
};