#include <chrono>
#include <fstream>
#include <iostream>

#ifndef STD_LENGTH
#define STD_LENGTH 100000
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

  template <class Type> void readOneDimensionalArray (char * fileName, oneDimensionalArrayType<Type> ODARefference);
  template <class Type> void outputOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference);

  virtual ~inputOutputOperations () {}
};

class maximumSumSequence {
private:
  validationRules __validations__;

  bool isOdd (int number);
  bool isEven (int number);

  template <class Type> Type getMaximumValue (Type parameterOne, Type parameterTwo);

  template<class Type> Type getMaximumSumSequenceOfOddNumbersODA (oneDimensionalArrayType<Type> ODARefference);
  template<class Type> Type getMaximumSumSequenceOfEvenNumbersODA (oneDimensionalArrayType<Type> ODARefference);

public:
  maximumSumSequence () {}

  template <class Type> Type getMaximumSumByParity (oneDimensionalArrayType<Type> ODARefference);

  virtual ~maximumSumSequence () {}
};
