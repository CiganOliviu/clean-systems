#include "maxPossibleBaseDef.hpp"

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

int NumberProperties::getMaximumValueNumber (int number) {

  if (__validations__.isNegative(number)) systemException("Unable to process negative values");
  if (__validations__.isZero(number)) systemException("Unable to process number as zero");

  int maximumValue = 0;

  while (number != 0) {

    if (maximumValue < number % 10)
        maximumValue = number % 10;

    number /= 10;
  }

  return maximumValue;
}

int NumberProperties::returnMaximuBaseNumber (int number) {

  int result = getMaximumValueNumber (number) + 1;

  return result;
}

int main(int argc, char const *argv[]) {

  NumberProperties properties;

  int number;

  std::cin >> number;

  auto start = high_resolution_clock::now();

  std::cout << properties.returnMaximuBaseNumber (number) << '\n' << '\n';

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
