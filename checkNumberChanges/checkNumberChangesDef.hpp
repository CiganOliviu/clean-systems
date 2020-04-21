/*
  Tasks:
    * get the number of digits of a number
    * duplicate a specific digit from the number
    * duplicate specific digits and return the unchange digits
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

class numberProcess {
private:
  validationRules __validations__;

public:
  numberProcess () {}

  int numberOfDigits (int number);
  int duplicateDigits (int number, int digit);

  virtual ~numberProcess () {}
};
