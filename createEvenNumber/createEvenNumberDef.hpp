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

  bool isEven (int number);
  int reverseNumber (int number);

public:
  numberProcess () {};

  int generateEvenNumber (int number);

  virtual ~numberProcess () {}
};
