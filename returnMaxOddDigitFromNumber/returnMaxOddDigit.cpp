#include "returnMaxOddDigitDef.hpp"

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

bool maxDigitProcessor::isOdd (int number) { 
  
  if (__validations__.isNegative (number)) throw systemException ("Unable to process negative data");

  if (number % 2 == 1) return true;

  return false;
}

int maxDigitProcessor::returnMaxValueFrom (int parameterOne, int parameterTwo) {

  if (parameterOne > parameterTwo) return parameterOne;

  return parameterTwo;
}

int maxDigitProcessor::returnMaxOddDigitFromANumber (int number) {

  if (__validations__.isNegative (number)) throw systemException("Unable to process negative data");
  if (__validations__.isZero (number)) throw systemException("Unable to process data as zero");

  int result = 0;
  int digit;

  while (number != 0) {
    
    digit = number % 10;

    if (isOdd(digit))
      result = returnMaxValueFrom(result, digit);

    number /= 10;
  }

  return result;
} 

int main (int argc, char const * argv[]) {

  maxDigitProcessor objectProcessor;

  int number;

  std::cin >> number;

  auto start = high_resolution_clock::now();

  std::cout << objectProcessor.returnMaxOddDigitFromANumber (number);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "\n\n\nTime taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}