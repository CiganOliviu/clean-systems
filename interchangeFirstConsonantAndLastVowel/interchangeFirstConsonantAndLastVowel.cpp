#include "interchangeFirstConsonantAndLastVowelDef.hpp"

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

bool stringWorkFlow::isVowel (char character) {

  if (strchr ("aeiouAEIOU", character) )
    return true;

  return false;
}

bool stringWorkFlow::isConsonant (char character) {

  if (strchr("aeiouAEIOU", character) )
    return false;

  return true;
}

int stringWorkFlow::getPositionLastVowel (oneDimensionalArrayType<char> dataWorkFlow) {
  
  if (__validations__.isZero(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process negative length");

  int LastVowelPosition = 0;

  for (int iterator = dataWorkFlow.startPoint; iterator < strlen (dataWorkFlow.oneDimensionalArray); iterator++)
    if (isVowel (dataWorkFlow.oneDimensionalArray[iterator]))
      LastVowelPosition = iterator;

  return LastVowelPosition;
}

int stringWorkFlow::getPositionFirstConsonant (oneDimensionalArrayType<char> dataWorkFlow) {
  
  if (__validations__.isZero(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process negative length");

  for (int iterator = dataWorkFlow.startPoint; iterator < strlen (dataWorkFlow.oneDimensionalArray); iterator++)
    if (isConsonant (dataWorkFlow.oneDimensionalArray[iterator]))
      return iterator;

  return -1;
}

void stringWorkFlow::interchangeValues (char * parameterOne, char * parameterTwo) {

  * parameterOne = * parameterOne + * parameterTwo;
  * parameterTwo = * parameterOne - * parameterTwo;
  * parameterOne = * parameterOne - * parameterTwo;
}

void stringWorkFlow::interchangeFirstConsonantAndLastVowel (oneDimensionalArrayType<char> dataWorkFlow) {
  
  if (__validations__.isZero(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process negative length");

  int firstConsonantPosition = getPositionFirstConsonant (dataWorkFlow);
  int lastVowelPosition = getPositionLastVowel (dataWorkFlow);

  interchangeValues (& dataWorkFlow.oneDimensionalArray[firstConsonantPosition], & dataWorkFlow.oneDimensionalArray[lastVowelPosition]);
}

int main (int argc, char const *argv[]) {

  oneDimensionalArrayType<char> string;
  inputOutputSystem IOSystem;
  stringWorkFlow workflow;

  string.length = 100;

  IOSystem.readOneDimensionalArray (string);

  auto start = high_resolution_clock::now();

  workflow.interchangeFirstConsonantAndLastVowel (string);

  IOSystem.outputOneDimensionalArray (string);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
