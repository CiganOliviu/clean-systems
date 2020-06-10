#include "outputVowelsFromStringDef.hpp"

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

void inputOutputSystem::readOneDimensionalArray (oneDimensionalArrayType<char> dataWorkFlow) {

  if (__validations__.isZero(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process negative length");

  std::cin.getline (dataWorkFlow.oneDimensionalArray, dataWorkFlow.length);

}

void inputOutputSystem::outputOneDimensionalArray (oneDimensionalArrayType<char> dataWorkFlow) {

  if (__validations__.isZero(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process negative length");

  std::cout << dataWorkFlow.oneDimensionalArray << '\n';
}

bool stringWorkFlow::isVowel (char element) {

  if (element == 'a' || element == 'e' || element == 'i' || element == 'o' || element == 'u')
    return true;

  return false;
}

void stringWorkFlow::outputVowelsFromString (oneDimensionalArrayType<char> dataWorkFlow) {

  if (__validations__.isZero(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process negative length");

  for (int iterator = dataWorkFlow.startPoint; iterator < dataWorkFlow.length + dataWorkFlow.endPoint; iterator++)
      if (isVowel(dataWorkFlow.oneDimensionalArray[iterator]))
        std::cout << dataWorkFlow.oneDimensionalArray[iterator] << " ";
}

int main (int argc, char const *argv[]) {

  oneDimensionalArrayType<char> string;
  inputOutputSystem IOSystem;
  stringWorkFlow workflow;

  string.length = 100;

  IOSystem.readOneDimensionalArray (string);

  auto start = high_resolution_clock::now();

  workflow.outputVowelsFromString (string);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
