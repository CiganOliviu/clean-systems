#include "deleteSequenceFromStringDef.hpp"

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

void stringWorkFlow::deleteSequenceFromString (oneDimensionalArrayType<char> dataWorkFlow, int size) {

  if (__validations__.isZero(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process negative length");

  int limit = strlen(dataWorkFlow.oneDimensionalArray) - 2;
  char sequence[100];
  int pivot;

  strcpy (sequence, dataWorkFlow.oneDimensionalArray);

  for (int iterator = dataWorkFlow.startPoint; iterator < limit; iterator++) {

    pivot = iterator;

    for (int jiterator = 0; jiterator < strlen(sequence); jiterator++)
      strcpy (sequence + pivot, sequence + pivot + 1);

    std::cout << sequence << '\n';

    strcpy (sequence, dataWorkFlow.oneDimensionalArray);
  }
}

int main (int argc, char const *argv[]) {

  oneDimensionalArrayType<char> string;
  inputOutputSystem IOSystem;
  stringWorkFlow workflow;

  int size = 3;

  string.length = 100;

  IOSystem.readOneDimensionalArray (string);

  auto start = high_resolution_clock::now();

  workflow.deleteSequenceFromString (string, size);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
