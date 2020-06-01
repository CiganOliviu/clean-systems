/*
  Tasks:
    * Giving the first termen of a specific string of numbers return the rest of them who are lower.
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

class stringOfNumbers {
private:
  validationRules __validations__;

public:
  stringOfNumbers () {}

  int generateSpecificTermRecursively (int index);
  int foundIndexForSpecificTerm (int term);

  virtual ~stringOfNumbers () {}
};

class inputOutputSystem {
private:
  validationRules __validations__;
  stringOfNumbers __stringObject__;

public:
  inputOutputSystem () {}

  void outputStringOfNumbers (int limit);

  virtual ~inputOutputSystem () {}
};