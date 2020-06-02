#include "sortCharArrayDef.hpp"

const char * systemException::what () const throw () {

  return processMessage.c_str();
}

bool validationRules::isNegative (char parameter[]) {

  if (strlen(parameter) < 0) return true;

  return false;
}

bool validationRules::isZero (char parameter[]) {

  if (strlen(parameter) == 0) return true;

  return false;
}

void inputOutputSystem::readOneDimensionalArray (oneDimensionalArrayType<char> ODAObject) {

  std::cin >> ODAObject.oneDimensionalArray;
}

void inputOutputSystem::outputOneDimensionalArray (oneDimensionalArrayType<char> ODAObject) {

  if (__validations__.isNegative(ODAObject.oneDimensionalArray)) throw systemException ("Unable to process negative length");
  if (__validations__.isZero(ODAObject.oneDimensionalArray)) throw systemException ("Unable to process length as zero");

  for (int iterator = ODAObject.startPoint; iterator < strlen(ODAObject.oneDimensionalArray) + ODAObject.endPoint; iterator++)
    std::cout << ODAObject.oneDimensionalArray[iterator];

  std::cout << '\n' << '\n' << '\n';
}

template <class Type> void arraySortEngine::interchangeValues (Type & parameterOne, Type & parameterTwo) {
  
  parameterOne = parameterOne + parameterTwo;
  parameterTwo = parameterOne - parameterTwo;
  parameterOne = parameterOne - parameterTwo;
}

template <class Type> void arraySortEngine::bubbleSortODA (oneDimensionalArrayType<Type> ODAObject) {

  if (__validations__.isNegative(ODAObject.oneDimensionalArray)) throw systemException ("Unable to process negative length");
  if (__validations__.isZero(ODAObject.oneDimensionalArray)) throw systemException ("Unable to process length as zero");

  for (int iterator = ODAObject.startPoint; iterator < strlen(ODAObject.oneDimensionalArray) + ODAObject.endPoint; iterator++)
    for (int jiterator = ODAObject.startPoint; jiterator < strlen(ODAObject.oneDimensionalArray) + ODAObject.endPoint; jiterator++)
      if (ODAObject.oneDimensionalArray[iterator] < ODAObject.oneDimensionalArray[jiterator])
        interchangeValues (ODAObject.oneDimensionalArray[iterator], ODAObject.oneDimensionalArray[jiterator]);

}

int main(int argc, char const *argv[]) {

  oneDimensionalArrayType<char> stringArray;
  inputOutputSystem IOSystem;
  arraySortEngine engine;

  IOSystem.readOneDimensionalArray (stringArray);

  auto start = high_resolution_clock::now();  

  engine.bubbleSortODA (stringArray);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  IOSystem.outputOneDimensionalArray (stringArray);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
