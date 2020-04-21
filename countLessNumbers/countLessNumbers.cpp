#include "countLessNumbersDef.hpp"

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

template <class Type> int dataProcessing::countLessNumbers (oneDimensionalArrayType<Type> ODARefferenceOne, oneDimensionalArrayType<Type> ODARefferenceTwo) {

  if (__validations__.isZero(ODARefferenceOne.length)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(ODARefferenceOne.length)) throw systemException ("Unable to process negative length");

  if (__validations__.isZero(ODARefferenceTwo.length)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(ODARefferenceTwo.length)) throw systemException ("Unable to process negative length");

  bool validationChecker = true;
  int howManyNumbersAreLess = 0;

  for (size_t iterator = ODARefferenceOne.startPoint; iterator < ODARefferenceOne.length + ODARefferenceOne.endPoint; iterator++) {
    for (size_t jiterator = ODARefferenceTwo.startPoint; jiterator < ODARefferenceTwo.length + ODARefferenceTwo.endPoint; jiterator++)
      if ((ODARefferenceOne.oneDimensionalArray[iterator] >= ODARefferenceTwo.oneDimensionalArray[jiterator]) && validationChecker)
        validationChecker = false;
    if (validationChecker)
      howManyNumbersAreLess += 1;

    validationChecker = true;
  }

  return howManyNumbersAreLess;
}


int main(int argc, char const *argv[]) {

  inputOutputOperations io;
  dataProcessing processing;
  oneDimensionalArrayType<int> ODAOne;
  oneDimensionalArrayType<int> ODATwo;

  io.readOneDimensionalArray ((char*)"arrayOneData.data", ODAOne);
  io.readOneDimensionalArray ((char*)"arrayTwoData.data", ODATwo);

  io.outputOneDimensionalArray (ODAOne);
  io.outputOneDimensionalArray (ODATwo);

  std::cout << processing.countLessNumbers (ODAOne, ODATwo);

  return 0;
}
