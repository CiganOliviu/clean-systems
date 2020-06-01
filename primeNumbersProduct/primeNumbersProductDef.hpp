/*
  Tasks:
    * return the product of prime numbers
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

class productProcessor {
private:
  validationRules __validations__;

  template <class Type> bool isPrime (Type number);

public:
  productProcessor () {}

  template <class Type> Type returnProductOfPrimeNumbers (Type number);

  virtual ~productProcessor () {}   
};
