/*
  convert a number to a specific base
  Tasks:
    * convert a number to a specific base
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

const char * systemException::what () const throw () {

  return processMessage.c_str();
}

class validationRules {

public:
  validationRules () {}

  template <class Type> bool isNegative (Type parameter);
  template <class Type> bool isZero (Type parameter);

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

class numberConversion {
private:
  validationRules __validations__;

public:
  numberConversion () {}

  std::string convertNumberToAnyBase (int number, int base);
  void reverseNumber (std::string & number);

  virtual ~numberConversion () {}
};

void numberConversion::reverseNumber (std::string & number) {

  int numberLength = number.length();

  for (size_t iterator = 0; iterator < numberLength / 2; iterator++)
    std::swap (number[iterator], number[numberLength - iterator - 1]);
}

std::string numberConversion::convertNumberToAnyBase (int number, int base) {

  if (__validations__.isNegative(number)) systemException("Unable to process negative values");
  if (__validations__.isZero(number)) systemException("Unable to process number as zero");

  std::string convertedNumber;

  while (number != 0) {

    convertedNumber.append(std::to_string(number % base));

    number /= base;
  }

  return convertedNumber;
}

int main(int argc, char const *argv[]) {

  numberConversion processNumber;
  int number, base;
  std::string processedNumber;

  std::cin >> number >> base;

  auto start = high_resolution_clock::now();

  processedNumber = processNumber.convertNumberToAnyBase(number, base);

  processNumber.reverseNumber(processedNumber);

  std::cout << processedNumber << '\n';

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
