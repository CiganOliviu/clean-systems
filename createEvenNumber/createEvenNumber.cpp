#include "createEvenNumberDef.hpp"

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

int inputOutputOperations::readNumber () {

  int number;

  std::cin >> number;

  return number;
}

void inputOutputOperations::outputNumber (int number) {

  std::cout << number << '\n';
}

bool numberProcess::isEven (int number) {

  if (number % 2 == 0) return true;

  return false;
}

int numberProcess::reverseNumber (int number) {

  int result = 0;
  int digit = 0;

  while (number != 0) {
    
    digit = number % 10;
    result = result * 10 + digit;

    number /= 10;
  }

  return result;
}

int numberProcess::generateEvenNumber (int number) {

  int result = 0;
  int digit = 0;

  while (number != 0) {

    digit = number % 10;

    if (isEven (digit))
      result = result * 10 + digit;

    number /= 10;
  }

  result = reverseNumber (result);

  return result;
}

int main(int argc, char const *argv[]) {

  inputOutputOperations IO;
  numberProcess processor;

  int number;
  int result;

  number = IO.readNumber ();

  auto start = high_resolution_clock::now();

  result = processor.generateEvenNumber (number);

  IO.outputNumber (result);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "\n\n\nTime taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
