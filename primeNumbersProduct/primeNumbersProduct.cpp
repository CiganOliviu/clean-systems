#include "primeNumbersProductDef.hpp"

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

template <class Type> bool productProcessor::isPrime (Type number) { 
  
  if (__validations__.isNegative (number)) throw systemException ("Unable to process negative data");
  if (__validations__.isZero (number)) return false;
  if (number == 2) return true;

  for (size_t iterator = 2; iterator <= number / 2; iterator++)
    if (number % iterator == 0)
      return false;

  return true;
}

template <class Type> Type productProcessor::returnProductOfPrimeNumbers (Type number) {

  if (__validations__.isNegative (number)) throw systemException("Unable to process negative data");
  if (__validations__.isZero (number)) throw systemException("Unable to process data as zero");

  int result = 1;

  for (size_t iterator = 2; iterator <= number; iterator++)
    if (isPrime(iterator))
      result *= iterator;

  return result;
}

int main (int argc, char const * argv[]) {

  productProcessor productObject;

  int number;

  std::cin >> number;

  auto start = high_resolution_clock::now();

  std::cout << productObject.returnProductOfPrimeNumbers (number);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "\n\n\nTime taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
