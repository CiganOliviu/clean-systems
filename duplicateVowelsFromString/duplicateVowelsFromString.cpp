#include "duplicateVowelsFromStringDef.hpp"

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

void stringWorkFlow::duplicateVowelsFromString (oneDimensionalArrayType<char> dataWorkFlow) {

  if (__validations__.isZero(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process negative length");

  char auxSequence[100];

  for (int iterator = dataWorkFlow.startPoint; iterator < strlen (dataWorkFlow.oneDimensionalArray); iterator++)
    if (isVowel (dataWorkFlow.oneDimensionalArray[iterator])) {

      strcpy (auxSequence, dataWorkFlow.oneDimensionalArray + iterator + 1);
      dataWorkFlow.oneDimensionalArray[iterator + 1] = dataWorkFlow.oneDimensionalArray[iterator];
      strcpy (dataWorkFlow.oneDimensionalArray + iterator + 2, auxSequence);

      iterator += 1;
    }
}

int main (int argc, char const *argv[]) {

  oneDimensionalArrayType<char> string;
  inputOutputSystem IOSystem;
  stringWorkFlow workflow;

  string.length = 100;

  IOSystem.readOneDimensionalArray (string);

  auto start = high_resolution_clock::now();

  workflow.duplicateVowelsFromString (string);

  IOSystem.outputOneDimensionalArray (string);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
