#include "arrayComplexProblemDef.hpp"

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

template <class Type> void inputOutputOperations::readFileOneDimensionalArray (char * fileName, oneDimensionalArrayType<Type> ODARefference) {

  std::ifstream stream (fileName, std::ios::in);
  
  Type value;
  int iterator = 1;

  if (stream.is_open()) {

    while (stream >> value) {
      
      ODARefference.oneDimensionalArray[iterator] = value;
      iterator += 1;
    }

    stream.close();
  }

  ODARefference.length = iterator - 1;
}

template <class Type> void inputOutputOperations::outputOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to handle length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to handle negative length");

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++)
      std::cout << ODARefference.oneDimensionalArray[iterator] << " ";

  std::cout << '\n' << '\n';
}

bool mathematicSupport::isPrime (int number) {

  if (__validations__.isNegative(number)) return false;
  if (number == 0) return false;
  if (number == 2) return true;

  for (size_t iterator = 2; iterator <= number / 2; iterator++)
    if (number % iterator == 0)
      return false;

  return true;
}

int mathematicSupport::returnSumOfDigits (int number) {

  if (__validations__.isNegative (number)) throw systemException ("Unable to process negative data");
  if (__validations__.isZero (number)) throw systemException ("Unable to process zero data");

  int digit;
  int result = 0;

  while (number != 0) {

    digit = number % 10;
    result += digit;

    number /= 10;
  }

  return result;
}

template <class Type> void mathematicSupport::interchangeValues (Type * parameterOne, Type * parameterTwo) {

  * parameterOne = * parameterOne + * parameterTwo;
  * parameterTwo = * parameterOne - * parameterTwo;
  * parameterOne = * parameterOne - * parameterTwo;
}

template <class Type> int mathematicSupport::findPositionToInsertInSortedArray (oneDimensionalArrayType<Type> ODARefference, Type valueToSearchFor) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to handle length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to handle negative length");

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++)
    if (valueToSearchFor >= ODARefference.oneDimensionalArray[iterator] && valueToSearchFor <= ODARefference.oneDimensionalArray[iterator])
      return iterator;

  return -1;
}

template <class Type> void arrayWorkFlow::outputPrimeNumbersFromArray (oneDimensionalArrayType<Type> ODARefference) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to handle length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to handle negative length");

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++)
    if (isPrime(ODARefference.oneDimensionalArray[iterator]))
      std::cout << ODARefference.oneDimensionalArray[iterator] << " ";
  
  std::cout << '\n' << '\n';
}

template <class Type> void arrayWorkFlow::deletePrimeNumbersFromArray (oneDimensionalArrayType<Type> ODARefference) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to handle length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to handle negative length");

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++)
    if (isPrime(ODARefference.oneDimensionalArray[iterator])) {
      for (size_t jiterator = iterator + 1; jiterator < ODARefference.length + ODARefference.endPoint; jiterator++)
        ODARefference.oneDimensionalArray[jiterator - 1] = ODARefference.oneDimensionalArray[jiterator];
        ODARefference.length -= 1;
        iterator -= 1;
      }
}

template <class Type> void arrayWorkFlow::sortByBubbleSort (oneDimensionalArrayType<Type> ODARefference) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to handle length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to handle negative length");

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++)
    for (size_t jiterator = ODARefference.startPoint; jiterator < ODARefference.length + ODARefference.endPoint; jiterator++)
      if (ODARefference.oneDimensionalArray[iterator] < ODARefference.oneDimensionalArray[jiterator])
        interchangeValues (& ODARefference.oneDimensionalArray[iterator], & ODARefference.oneDimensionalArray[jiterator]);
}

template <class Type> void arrayWorkFlow::replaceDoubledValuesFromODAByDigitsSum (oneDimensionalArrayType<Type> ODARefference) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to handle length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to handle negative length");

  int digitsSum;
  int positionToChange = 0;

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint - 1; iterator++)
    if (ODARefference.oneDimensionalArray[iterator] == ODARefference.oneDimensionalArray[iterator + 1]) {

      digitsSum = returnSumOfDigits (ODARefference.oneDimensionalArray[iterator]);

      positionToChange = findPositionToInsertInSortedArray (ODARefference, digitsSum);

      ODARefference.oneDimensionalArray[positionToChange] = digitsSum;
    }
}

int main (int argc, const char * argv[]) {

  oneDimensionalArrayType<int> ODA;
  inputOutputOperations IOoperations;
  arrayWorkFlow workflow;
  char * fileName = (char*)"ODA.data";

  ODA.startPoint = 1;
  ODA.endPoint = 1;

  auto start = high_resolution_clock::now();

  IOoperations.readFileOneDimensionalArray<int> (fileName, ODA);
  IOoperations.outputOneDimensionalArray<int> (ODA);

  workflow.outputPrimeNumbersFromArray<int> (ODA);
  
  workflow.deletePrimeNumbersFromArray<int> (ODA);
  IOoperations.outputOneDimensionalArray<int> (ODA);

  workflow.sortByBubbleSort<int> (ODA);
  IOoperations.outputOneDimensionalArray<int> (ODA);

  workflow.replaceDoubledValuesFromODAByDigitsSum<int> (ODA);
  workflow.sortByBubbleSort<int> (ODA);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "\n\n\nTime taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}