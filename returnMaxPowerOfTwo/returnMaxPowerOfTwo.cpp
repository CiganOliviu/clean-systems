#include "returnMaxPowerOfTwoDef.hpp"

const char * systemException::what () const throw () {

  return processMessage.c_str();
}

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

bool numberProcessor::isPowerOfTwo (int number) {

  if (__validations__.isNegative (number)) throw systemException ("Unable to process negative number");
  if (__validations__.isZero (number)) throw systemException ("Unable to process number value zero");

  int power = 1;

  for (int iterator = 1; iterator <= number; iterator++) {

    power *= 2;

    if (power == number)
      return true;
  }

  return false;
}

int numberProcessor::returnMaxPowerOfTwoCloseToLimit (int number) {

  if (__validations__.isNegative (number)) throw systemException ("Unable to process negative number");
  if (__validations__.isZero (number)) throw systemException ("Unable to process number value zero");

  for (int iterator = number; iterator >= 1; iterator--)
    if (isPowerOfTwo (iterator))
      return iterator;

  return 1;
}

int main (int argc, char const * argv[]) {

  numberProcessor processorObject;

  int number;

  std::cin >> number;

  auto start = high_resolution_clock::now();

  std::cout << processorObject.returnMaxPowerOfTwoCloseToLimit (number);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "\n\n\nTime taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
