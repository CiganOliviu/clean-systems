#include "commonPropertiesInSequencesDef.hpp"

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

template <class Type> Type processData::returnMaximumValue (Type numberOne, Type numberTwo) {

  if (numberOne > numberTwo)
    return numberOne;

  return numberTwo;
}

template <class Type> int processData::getMaximumLengthOfSequence (oneDimensionalArrayType<Type> ODARefference, Type divisor) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to process negative length");

  int result = 0;
  int lengthOfSequence = 0;

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++)
    if (ODARefference.oneDimensionalArray[iterator] % divisor == 0)
      lengthOfSequence += 1;
    else
      lengthOfSequence = 0;

    result = returnMaximumValue(result, lengthOfSequence);

  return result;
}

template <class Type> int processData::getNumberOfDivisors (oneDimensionalArrayType<Type> ODARefference, Type divisor) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to process negative length");

  int result = 0;

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++)
    if (ODARefference.oneDimensionalArray[iterator] % divisor == 0)
      result += 1;

  return result;
}

int main(int argc, char const *argv[]) {

  oneDimensionalArrayType<int> ODAObject;
  inputOutputOperations io;
  processData processor;

  int divisor;

  std::cin >> divisor;

  auto start = high_resolution_clock::now();

  io.readOneDimensionalArray<int> ((char*)"ODA.data", ODAObject);
  io.outputOneDimensionalArray<int> (ODAObject);

  std::cout << processor.getNumberOfDivisors (ODAObject, divisor) << '\n';

  std::cout << processor.getMaximumLengthOfSequence (ODAObject, divisor) << '\n';

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
