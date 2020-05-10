/*
  Tasks:
    * Output maximum possible base for a number
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

class NumberProperties {
private:
  validationRules __validations__;
  
  int getMaximumValueNumber (int number);

public:
  NumberProperties () {}

  int returnMaximuBaseNumber (int maxDigit);

  virtual ~NumberProperties () {}
};