#include "removeFromCharArrayProblemDef.hpp"

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

  std::cin.getline(dataWorkFlow.oneDimensionalArray, dataWorkFlow.length);

}

void inputOutputSystem::printOneDimensionalArray (oneDimensionalArrayType<char> dataWorkFlow) {

  std::cout << dataWorkFlow.oneDimensionalArray;
}

void stringWorkFlow::removeAllFloatingNumbersFromSequence (oneDimensionalArrayType<char> dataWorkFlow) {

  if (__validations__.isZero(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process negative length");

  char * CharPointer;

  CharPointer = strtok(dataWorkFlow.oneDimensionalArray, " ");

  while (CharPointer) {

    if (!strchr(CharPointer, '.'))
      std::cout << CharPointer << " ";

    CharPointer = strtok(NULL, " ");
  }

  std::cout << '\n' << '\n' << '\n';
}

int main(int argc, char const *argv[]) {

  oneDimensionalArrayType<char> string;

  inputOutputSystem IOSystem;
  stringWorkFlow StringWork;

  string.length = 100;

  IOSystem.readOneDimensionalArray (string);

  auto start = high_resolution_clock::now();

  StringWork.removeAllFloatingNumbersFromSequence (string);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
