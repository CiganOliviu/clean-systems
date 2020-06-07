/*
  Tasks:
    * get the product of prime digits from a number, just once. For example the number 1223344 the product will be 6 (2 * 3)
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
  template <class Type> bool isZeroOrNegative (Type parameter);

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

class portData {

public:
  portData () {}

  template <class Type> void portOneDimensionalArray (oneDimensionalArrayType<Type> ODAObjectOne, oneDimensionalArrayType<Type> ODAObjectTwo);

  virtual ~portData () {}
};

class numberProcess {
private:
  validationRules __validations__;
  portData __port_sys__;

  bool isPrime (int number);
  oneDimensionalArrayType<int> saveDataAsOneDimensionalArray (int number);
  int returnProductArray (oneDimensionalArrayType<int> ODAObject);

public:
  numberProcess () {}

  int getDigitsProduct (int number);

  virtual ~numberProcess () {}
};
