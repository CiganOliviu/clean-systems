#include "primeDigitsProductOneTimeDef.hpp"

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

template <class Type> void portData::portOneDimensionalArray (oneDimensionalArrayType<Type> ODAObjectOne, oneDimensionalArrayType<Type> ODAObjectTwo) {

  ODAObjectOne.length = ODAObjectTwo.length;
  ODAObjectOne.startPoint = ODAObjectTwo.startPoint;
  ODAObjectOne.endPoint = ODAObjectTwo.endPoint;

  for (size_t iterator = ODAObjectOne.startPoint; iterator < ODAObjectOne.length + ODAObjectOne.endPoint; iterator++)
    ODAObjectOne.oneDimensionalArray[iterator] = ODAObjectTwo.oneDimensionalArray[iterator];
}

bool numberProcess::isPrime (int number) {

  if (__validations__.isNegative (number)) throw systemException ("Can't handle negative data");
  if (__validations__.isZero (number)) return false;
  if (number == 2) return true;

  for (int iterator = 2; iterator <= number / 2; iterator++)
    if (number % iterator == 0) return false;

  return true; 
}

oneDimensionalArrayType<int> numberProcess::saveDataAsOneDimensionalArray (int number) {

  if (__validations__.isNegative (number)) throw systemException ("Can't handle negative data");
  if (__validations__.isZero (number)) throw systemException ("Can't handle null data");

  oneDimensionalArrayType<int> frequencyArray;  
  int digit;  

  frequencyArray.length = 9;

  while (number != 0) {

    digit = number % 10;

    if (isPrime(digit))
      frequencyArray.oneDimensionalArray[digit] = 1;

    number /= 10;
  }

  return frequencyArray;
}

int numberProcess::returnProductArray (oneDimensionalArrayType<int> ODAObject) {

  if (__validations__.isNegative (ODAObject.length)) throw systemException ("Can't handle negative length");
  if (__validations__.isZero (ODAObject.length)) throw systemException ("Can't handle null length");

  int result = 1;

  for (int iterator = ODAObject.startPoint; iterator < ODAObject.length + ODAObject.endPoint; iterator++)
    if (ODAObject.oneDimensionalArray[iterator] == 1)
      result *= iterator;

  return result; 
}

int numberProcess::getDigitsProduct (int number) {

  if (__validations__.isNegative (number)) throw systemException ("Can't handle negative data");
  if (__validations__.isZero (number)) throw systemException ("Can't handle null data");

  int result = 1;

  oneDimensionalArrayType<int> frequencyODA;

  __port_sys__.portOneDimensionalArray (frequencyODA, saveDataAsOneDimensionalArray(number));

  result = returnProductArray (frequencyODA);

  return result;
}

int main (int argc, char const * argv[]) {

  numberProcess __processor__;
  int number;
  int result;

  std::cin >> number;

  auto start = high_resolution_clock::now();

  result = __processor__.getDigitsProduct (number);

  std::cout << result << '\n';

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}