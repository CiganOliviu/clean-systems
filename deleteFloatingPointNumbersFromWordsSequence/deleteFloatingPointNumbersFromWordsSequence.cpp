#include "deleteFloatingPointNumbersFromWordsSequenceDef.hpp"

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

  std::cin.getline(ODAObject.oneDimensionalArray, ODAObject.length);
}

void inputOutputSystem::outputOneDimensionalArray (oneDimensionalArrayType<char> ODAObject) {

  if (__validations__.isNegative(ODAObject.oneDimensionalArray)) throw systemException ("Unable to process negative length");
  if (__validations__.isZero(ODAObject.oneDimensionalArray)) throw systemException ("Unable to process length as zero");

  for (int iterator = ODAObject.startPoint; iterator < strlen(ODAObject.oneDimensionalArray) + ODAObject.endPoint; iterator++)
    std::cout << ODAObject.oneDimensionalArray[iterator];

  std::cout << '\n' << '\n' << '\n';
}

void removerProcessor::RemoveFloatingPointNumbersFromWordsSequence (oneDimensionalArrayType<char> ODAObject) {

  if (__validations__.isNegative(ODAObject.oneDimensionalArray)) throw systemException ("Unable to process negative length");
  if (__validations__.isZero(ODAObject.oneDimensionalArray)) throw systemException ("Unable to process length as zero");

  char * PointerChar;

  PointerChar = strtok(ODAObject.oneDimensionalArray, " ");

  while (PointerChar) {

    if (!strchr(PointerChar, ','))
      std::cout << PointerChar << " ";

    PointerChar = strtok(NULL, " ");
  }
}

int main (int argc, char const * argv[]) {

  oneDimensionalArrayType<char> charArray;
  inputOutputSystem IOSys;
  removerProcessor __processor__;

  charArray.length = 200;

  auto start = high_resolution_clock::now();

  IOSys.readOneDimensionalArray (charArray);
  
  __processor__.RemoveFloatingPointNumbersFromWordsSequence (charArray);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "\n\n\nTime taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}