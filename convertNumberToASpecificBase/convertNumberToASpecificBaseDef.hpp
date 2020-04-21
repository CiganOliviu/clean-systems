/*
  convert a number to a specific base
  Tasks:
    * convert a number to a specific base
*/

#include <chrono>
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

  virtual ~validationRules () {}
};

class numberConversion {
private:
  validationRules __validations__;

public:
  numberConversion () {}

  std::string convertNumberToAnyBase (int number, int base);
  void reverseNumber (std::string & number);

  virtual ~numberConversion () {}
};
