#include "deleteFloatingFromStringDef.hpp"

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

void stringWorkFlow::readOneDimensionalArray (oneDimensionalArrayType<char> dataWorkFlow) {

  if (__validations__.isZero(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process negative length");

  std::cin.getline(dataWorkFlow.oneDimensionalArray, 100);

}

void stringWorkFlow::removeAllDots (oneDimensionalArrayType<char> dataWorkFlow) {

  if (__validations__.isZero(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process negative length");

  char * auxPointer;

  auxPointer = strtok(dataWorkFlow.oneDimensionalArray, " ");

  while (auxPointer != NULL) {

    if (!strstr(auxPointer, "."))
      std::cout << auxPointer;

    std::cout << " ";

    auxPointer = strtok(NULL, " ");
  }

  std::cout << '\n' << '\n';
}

int main(int argc, char const *argv[]) {

  stringWorkFlow __workFlow__;
  oneDimensionalArrayType<char> string;

  __workFlow__.readOneDimensionalArray (string);

  auto start = high_resolution_clock::now();

  __workFlow__.removeAllDots (string);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
