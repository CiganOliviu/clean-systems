#include "factorialIntervalDef.hpp"

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

template <class Type> bool validationRules::areEqual (Type parameterOne, Type parameterTwo) {

  if (parameterOne == parameterTwo) return true;

  return false;
}

int inputOutputOperations::readNumber () {

  int numar;

  std::cin >> numar;

  return numar;
}

void inputOutputOperations::outputNumber (int numar) {

  std::cout << numar;
}

int factorialInterval::returnFactorialValue (int numar) {

  if (numar == 0 || numar == 1) return 1;

  return numar * returnFactorialValue (numar - 1);
}

limits factorialInterval::returnFactorialInterval (int number) {

  limits interval;

  interval.minimLimit = returnFactorialValue (number - 1);
  interval.minimLimit += 1;

  interval.maximLimit = returnFactorialValue (number + 1);
  interval.maximLimit -= 1;

  return interval;
}

int factorialInterval::returnIntervalDifference (limits interval) {

  int result;

  result = interval.maximLimit - interval.minimLimit;

  return result; 
}

int main (int argc, char const * argv[]) {

  inputOutputOperations io;
  factorialInterval interval;

  int number;

  auto start = high_resolution_clock::now();

  number = io.readNumber ();

  std::cout << interval.returnIntervalDifference(interval.returnFactorialInterval(number));

  std::cout << '\n';
  
  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}