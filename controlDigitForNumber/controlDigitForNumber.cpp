#include "controlDigitForNumberDef.hpp"

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

  std::cout << number << " ";
}

int numberProcess::sumOfDigits (int number) {

  int result = 0;
  int digit = 0;

  while (number != 0) {

    digit = number % 10;
    result += digit;

    number /= 10;
  }

  return result;
}

int numberProcess::getControlDigit (int number) {

  int sum = sumOfDigits (number);

  while (sum > 9) {

    sum = sumOfDigits (sum);
  }

  return sum;
}

int main(int argc, char const *argv[]) {

  auto start = high_resolution_clock::now();

  numberProcess process;
  inputOutputOperations io;

  int number;
  int controlDigit = -1;

  number = io.readNumber ();

  controlDigit = process.getControlDigit (number);

  io.outputNumber (controlDigit);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "\n\n\nTime taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
