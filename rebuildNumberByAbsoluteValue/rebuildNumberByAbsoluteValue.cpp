#include "rebuildNumberByAbsoluteValuedef.hpp"

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

template <class Type> Type numbersProcessor::returnAbsoluteValue (Type parameterOne, Type parameterTwo) {

  Type result;

  result = abs (parameterOne - parameterTwo);

  return result;
}

template <class Type> Type numbersProcessor::reverseNumber (Type number, validationRules __validations__) {

  if (__validations__.isNegative (number)) throw systemException ("Unable to process negative data");
  if (__validations__.isZero (number)) throw systemException ("Unable to process data as zero");

  Type result = 0;
  Type digit = 0;

  while (number != 0) {

      digit = number % 10;

      result = result * 10 + digit;

      number /= 10;
  }

  return result;
}

template <class Type> Type numbersProcessor::constructNumber (Type number, validationRules __validations__) {

  if (__validations__.isNegative (number)) throw systemException ("Unable to process negative data");
  if (__validations__.isZero (number)) throw systemException ("Unable to process data as zero");

  Type result = 0;
  Type digit = 0;

  while (number > 0) {

      digit = number % 10;
      result = result * 10 + digit;

      if (number > 10)
        result = result * 10 + returnAbsoluteValue (number % 10, (number % 100) / 10);

      number /= 10;
  }

  result = reverseNumber (result, __validations__);

  return result;
}

int main (int argc, char const * argv[]) {

  validationRules __validations__;
  numbersProcessor processor;
  int number;

  std::cin >> number;

  auto start = high_resolution_clock::now();

  std::cout << processor.constructNumber (number, __validations__);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "\n\n\nTime taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
