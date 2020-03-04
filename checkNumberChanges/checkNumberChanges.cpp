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

const char * systemException::what () const throw () {

  return processMessage.c_str();
}

class validationRules {

public:
  validationRules () {}

  template <class Type> bool isNegative (Type parameter);
  template <class Type> bool isZero (Type parameter);
  template <class Type> bool isZeroOrNegative (Type parameter);

  virtual ~validationRules () {}
};

template <class Type> bool validationRules::isNegative (Type parameter) {

  if (parameter < 0) return true;

  return false;
}

template <class Type> bool validationRules::isZero (Type parameter) {

  if (parameter == 0) return true;

  return false;
}

template <class Type> bool validationRules::isZeroOrNegative (Type parameter) {

  if (parameter <= 0) return true;

  return false;
}

class numberProcess {
private:
  validationRules __validations__;

public:
  numberProcess () {}

  int numberOfDigits (int number);
  int duplicateDigits (int number, int digit);

  virtual ~numberProcess () {}
};

int numberProcess::numberOfDigits (int number) {

  if (__validations__.isZeroOrNegative(number)) throw systemException ("Unable to process negative or zero value");

  int digitsIndex = 0;

  while (number != 0) {

    digitsIndex += 1;
    number /= 10;
  }

  return digitsIndex;
}

int numberProcess::duplicateDigits (int number, int digit) {

  if (__validations__.isZeroOrNegative(number)) throw systemException ("Unable to process negative or zero value");

  int processedNumber = 0;
  int auxiliarValue = 1;

  while (number != 0) {

    if (digit == number % 10) {
      processedNumber += number % 10 * auxiliarValue;
      auxiliarValue *= 10;
      processedNumber += number % 10 * auxiliarValue;
    }
    else processedNumber += number % 10 * auxiliarValue;

    auxiliarValue *= 10;

    number /= 10;
  }

  return processedNumber;
}

int main(int argc, char const *argv[]) {

  numberProcess processor;
  int number;
  int limitsParamOne, limitsParamTwo;
  int auxiliarNumberRefference, doubleDuplicatedNumber;

  std::cin >> number >> limitsParamOne >> limitsParamTwo;

  auxiliarNumberRefference = processor.duplicateDigits (number, limitsParamOne);
  doubleDuplicatedNumber = processor.duplicateDigits (auxiliarNumberRefference, limitsParamTwo);

  std::cout << processor.numberOfDigits(doubleDuplicatedNumber) - processor.numberOfDigits(number);

  return 0;
}
