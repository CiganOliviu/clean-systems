#include "howManyIncludedArraysDef.hpp"

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

int dataProcessing::getMinimumValue (int parameterOne, int parameterTwo) {

  if (parameterOne > parameterTwo) return parameterTwo;

  return parameterOne;
}

template <class Type> int dataProcessing::countAssociatedElements (oneDimensionalArrayType<Type> ODARefference, Type associatedElement) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to process negative length");

  int counter = 0;

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++)
    if (associatedElement == ODARefference.oneDimensionalArray[iterator])
      counter += 1;

  return counter;
}

template <class Type> int dataProcessing::countIncludedArrays (oneDimensionalArrayType<Type> ODARefferenceOne, oneDimensionalArrayType<Type> ODARefferenceTwo) {

  if (__validations__.isZero(ODARefferenceOne.length)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(ODARefferenceOne.length)) throw systemException ("Unable to process negative length");

  if (__validations__.isZero(ODARefferenceTwo.length)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(ODARefferenceTwo.length)) throw systemException ("Unable to process negative length");

  int minimumValue = INT_MAX;
  int auxiliarValue = 0;

  for (size_t iterator = ODARefferenceOne.startPoint; iterator < ODARefferenceOne.length + ODARefferenceOne.endPoint; iterator++) {
    auxiliarValue = countAssociatedElements (ODARefferenceTwo, ODARefferenceOne.oneDimensionalArray[iterator]);
    minimumValue = getMinimumValue(minimumValue, auxiliarValue);
  }

  return minimumValue;
}

int main(int argc, char const *argv[]) {

  inputOutputOperations io;
  dataProcessing processing;
  oneDimensionalArrayType<int> ODAOne;
  oneDimensionalArrayType<int> ODATwo;

  auto start = high_resolution_clock::now();

  io.readOneDimensionalArray ((char*)"arrayOneData.data", ODAOne);
  io.readOneDimensionalArray ((char*)"arrayTwoData.data", ODATwo);

  io.outputOneDimensionalArray (ODAOne);
  io.outputOneDimensionalArray (ODATwo);

  std::cout << processing.countIncludedArrays (ODATwo, ODAOne) << '\n';

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
