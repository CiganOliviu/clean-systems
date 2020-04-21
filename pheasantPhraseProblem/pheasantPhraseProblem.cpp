#include "pheasantPhraseProblemDef.hpp"

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

template <class Type> void inputOutputOperations::readOneDimensionalArray (char * fileName, oneDimensionalArrayType<Type> ODARefference) {

  std::ifstream dataStream(fileName, std::ios::in);
  Type data;

  if (dataStream.is_open()) {

    while (dataStream >> data) {
        ODARefference.oneDimensionalArray[ODARefference.length] = data;
        ODARefference.length += 1;
    }

    if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to process length as zero");
    if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to process negative length");

    dataStream.close();
  }
  else
    throw systemException ("Unable to open file");
}

template <class Type> void inputOutputOperations::outputOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to process negative length");

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++)
    std::cout << ODARefference.oneDimensionalArray[iterator] << " ";
  std::cout << '\n' << '\n' << '\n';
}

int dataProcessing::getTheLastDigit (int number) {

  if (__validations__.isZero(number)) throw systemException ("Unable to process number as zero");
  if (__validations__.isNegative(number)) throw systemException ("Unable to process negative number");

  return number % 10;
}

int dataProcessing::getTheFirstDigit (int number) {

  if (__validations__.isZero(number)) throw systemException ("Unable to process number as zero");
  if (__validations__.isNegative(number)) throw systemException ("Unable to process negative number");

  while (number >= 10)
    number /= 10;

  return number;
}

int dataProcessing::maxNumber (int numberOne, int numberTwo) {

  if (numberOne > numberTwo) return numberOne;

  return numberTwo;
}

template <class Type> int dataProcessing::longestPheasantPhrase (oneDimensionalArrayType<Type> ODARefference) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to process negative length");

  int longestPhrase = 1;
  int maxPhrase = 0;

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint - 1; iterator++) {
    if (getTheLastDigit(ODARefference.oneDimensionalArray[iterator]) == getTheFirstDigit(ODARefference.oneDimensionalArray[iterator + 1]))
      longestPhrase += 1;
    else
      longestPhrase = 1;

    maxPhrase = maxNumber (maxPhrase, longestPhrase);
  }

  return maxPhrase;
}

int main(int argc, char const *argv[]) {

  inputOutputOperations io;
  dataProcessing processing;
  oneDimensionalArrayType<int> ODAObject;

  io.readOneDimensionalArray ((char*)"ODA.data", ODAObject);

  auto start = high_resolution_clock::now();

  io.outputOneDimensionalArray (ODAObject);

  std::cout << processing.longestPheasantPhrase (ODAObject);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
