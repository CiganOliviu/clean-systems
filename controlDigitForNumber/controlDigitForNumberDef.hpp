/*
  numbers process
  Tasks:
    * read one dimensional array
    * output one dimensional array
    * remove the duplications and sort every number
    * print out the frequency of every number that appears in array
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

class inputOutputOperations {
private:
  validationRules __validations__;

public:
  inputOutputOperations () {}

  int readNumber ();
  void outputNumber (int number);

  virtual ~inputOutputOperations () {}
};

class numberProcess {
private:
  validationRules __validations__;

  int sumOfDigits (int number);

public:
  numberProcess () {};

  int getControlDigit (int number);

  virtual ~numberProcess () {}
};
