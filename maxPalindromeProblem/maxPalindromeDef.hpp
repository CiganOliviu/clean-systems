#include <chrono>
#include <fstream>
#include <iostream>
#include <math.h>

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
  template <class Type> bool areEqual (Type parameterOne, Type parameterTwo);

  virtual ~validationRules () {}
};

template <class Type> class oneDimensionalArrayType {
private:
  int standardSize = 0;

public:
  oneDimensionalArrayType () {}

  int & length = standardSize;
  int startPoint = standardSize;
  int endPoint = standardSize;

  Type * oneDimensionalArray = new Type[STD_LENGTH];

  virtual ~oneDimensionalArrayType () {}
};

class inputOutputOperations {
private:
  validationRules __validations__;

public:
  inputOutputOperations () {}

  template <class Type> void readFileOneDimensionalArray (char * fileName, oneDimensionalArrayType<Type> ODARefference);
  template <class Type> void outputOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference);

  virtual ~inputOutputOperations () {}
};

class mathematicSupport {
private:
  validationRules __validations__;

public:
  
  mathematicSupport () {}

  bool isPalindrome (int number);
  int getMaxValueOf (int parameterOne, int parameterTwo);

  virtual ~mathematicSupport () {}
};

class palindromeWorkFlow : public mathematicSupport {
private:
  validationRules __validations__;
  
public:
  palindromeWorkFlow () {}

  template <class Type> Type getMaximumPalindromeValue (oneDimensionalArrayType<Type> ODARefference);
  template <class Type> Type reportAppearanceFrequency (oneDimensionalArrayType<Type> ODARefference, Type valueToCheck);

  virtual ~palindromeWorkFlow () {}
};