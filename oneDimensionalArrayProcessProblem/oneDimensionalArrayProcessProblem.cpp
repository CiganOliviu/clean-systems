#include "oneDimensionalArrayProcessProblemDef.hpp"

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

template <class Type> void processData::interchangeValues (Type * parameterOne, Type * parameterTwo) {

  *parameterOne = *parameterOne + *parameterTwo;
  *parameterTwo = *parameterOne - *parameterTwo;
  *parameterOne = *parameterOne - *parameterTwo;
}

template <class Type> bool processData::isPrime (Type parameter) {

  if (parameter <= 0) return false;

  if (parameter == 2) return true;

  for (size_t iterator = 2; iterator <= parameter / 2; iterator++)
    if (parameter % iterator == 0) return false;

  return true;
}

template <class Type> oneDimensionalArrayType<Type> processData::getPrimeValueOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to process negative length");

  oneDimensionalArrayType<Type> primeValuesOneDimensionalArray;

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++)
    if (isPrime(ODARefference.oneDimensionalArray[iterator])) {
      primeValuesOneDimensionalArray.oneDimensionalArray[primeValuesOneDimensionalArray.length] = ODARefference.oneDimensionalArray[iterator];
      primeValuesOneDimensionalArray.length += 1;
    }

  return primeValuesOneDimensionalArray;
}

template <class Type> oneDimensionalArrayType<Type> processData::getNonPrimeValueOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to process negative length");

  oneDimensionalArrayType<Type> nonePrimeValuesOneDimensionalArray;

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++)
    if (!isPrime(ODARefference.oneDimensionalArray[iterator])) {
      nonePrimeValuesOneDimensionalArray.oneDimensionalArray[nonePrimeValuesOneDimensionalArray.length] = ODARefference.oneDimensionalArray[iterator];
      nonePrimeValuesOneDimensionalArray.length += 1;
    }

  return nonePrimeValuesOneDimensionalArray;
}

template <class Type> void processData::bubbleSort (oneDimensionalArrayType<Type> ODARefference) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to process negative length");

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint - 1; iterator++)
      for (size_t jiterator = ODARefference.startPoint; jiterator < ODARefference.length + ODARefference.endPoint - iterator - 1; jiterator++)
        if (ODARefference.oneDimensionalArray[jiterator] > ODARefference.oneDimensionalArray[jiterator + 1])
          interchangeValues (&ODARefference.oneDimensionalArray[jiterator], &ODARefference.oneDimensionalArray[jiterator + 1]);
}

template <class Type> void objectsWorkFlow::portData (oneDimensionalArrayType<Type> ODARefferenceOne, oneDimensionalArrayType<Type> ODARefferenceTwo) {

  if (__validations__.isZero(ODARefferenceTwo.length)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(ODARefferenceTwo.length)) throw systemException ("Unable to process negative length");

  ODARefferenceOne.length = ODARefferenceTwo.length;
  ODARefferenceOne.startPoint = ODARefferenceTwo.startPoint;
  ODARefferenceOne.endPoint = ODARefferenceTwo.endPoint;

  for (size_t iterator = ODARefferenceOne.startPoint; iterator < ODARefferenceOne.length + ODARefferenceOne.endPoint; iterator++)
    ODARefferenceOne.oneDimensionalArray[iterator] = ODARefferenceTwo.oneDimensionalArray[iterator];
}

int main(int argc, char const *argv[]) {

  processData processDataObject;
  objectsWorkFlow objectsRefference;
  inputOutputOperations io;
  oneDimensionalArrayType<int> ODAObject;
  oneDimensionalArrayType<int> primeValuesODA;
  oneDimensionalArrayType<int> nonePrimeValuesODA;

  auto start = high_resolution_clock::now();

  io.readOneDimensionalArray<int> ((char*)"ODA.data", ODAObject);
  io.outputOneDimensionalArray<int> (ODAObject);

  objectsRefference.portData<int> (primeValuesODA, processDataObject.getPrimeValueOneDimensionalArray<int> (ODAObject));
  io.outputOneDimensionalArray<int> (primeValuesODA);

  objectsRefference.portData<int> (nonePrimeValuesODA, processDataObject.getNonPrimeValueOneDimensionalArray<int> (ODAObject));
  io.outputOneDimensionalArray<int> (nonePrimeValuesODA);

  processDataObject.bubbleSort (primeValuesODA);
  io.outputOneDimensionalArray (primeValuesODA);

  processDataObject.bubbleSort (nonePrimeValuesODA);
  io.outputOneDimensionalArray (nonePrimeValuesODA);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
