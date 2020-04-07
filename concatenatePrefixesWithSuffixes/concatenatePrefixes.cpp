/*
  prefixes of a string
  Tasks:
    * print all combination of prefixes of a string
*/

#include <chrono>
#include <fstream>
#include <iostream>
#include <string.h>

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

const char * systemException::what () const throw () {

  return processMessage.c_str();
}

class validationRules {

public:
  validationRules () {}

  bool isNegative (char parameter[]);
  bool isZero (char parameter[]);

  virtual ~validationRules () {}
};

bool validationRules::isNegative (char parameter[]) {

  if (strlen(parameter) < 0) return true;

  return false;
}

bool validationRules::isZero (char parameter[]) {

  if (strlen(parameter) == 0) return true;

  return false;
}

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

class stringWorkFlow {
private:
  validationRules __validations__;

public:
  stringWorkFlow () {}

  void readOneDimensionalArray (oneDimensionalArrayType<char> dataWorkFlow);
  void printConcatenatedPrefixes (oneDimensionalArrayType<char> dataWorkFlow);

  virtual ~stringWorkFlow () {}
};

void stringWorkFlow::readOneDimensionalArray (oneDimensionalArrayType<char> dataWorkFlow) {

  if (__validations__.isZero(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process negative length");

  std::cin >> dataWorkFlow.oneDimensionalArray;

}

void stringWorkFlow::printConcatenatedPrefixes (oneDimensionalArrayType<char> dataWorkFlow) {

  int jiterator = 1;

  while (jiterator <= strlen (dataWorkFlow.oneDimensionalArray)) {

    for (size_t iterator = 0; iterator < jiterator; iterator++)
      std::cout << dataWorkFlow.oneDimensionalArray[iterator];


    for (size_t iterator = 0; iterator < jiterator; iterator++)
      std::cout << dataWorkFlow.oneDimensionalArray[strlen(dataWorkFlow.oneDimensionalArray) - iterator - 1];

    std::cout << '\n';

    jiterator += 1;
  }
}

int main(int argc, char const *argv[]) {

  stringWorkFlow __workFlow__;
  oneDimensionalArrayType<char> string;

  __workFlow__.readOneDimensionalArray (string);

  auto start = high_resolution_clock::now();

  __workFlow__.printConcatenatedPrefixes (string);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
