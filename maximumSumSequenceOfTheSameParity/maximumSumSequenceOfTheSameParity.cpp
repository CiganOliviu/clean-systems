#include "maximumSumSequenceOfTheSameParityDef.hpp"

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

bool maximumSumSequence::isOdd (int number) {

  if (__validations__.isNegative (number)) throw systemException ("Unable to process negative number");
  if (__validations__.isZero (number)) throw systemException ("Unable to process number as zero");

  if (number % 2 == 1)
    return true;

  return false;
}

bool maximumSumSequence::isEven (int number) {

  if (number % 2 == 0)
    return true;

  return false;
}

template <class Type> Type maximumSumSequence::getMaximumValue (Type parameterOne, Type parameterTwo) {

  if (parameterOne > parameterTwo)
    return parameterOne;

  return parameterTwo;
}

template<class Type> Type maximumSumSequence::getMaximumSumSequenceOfOddNumbersODA (oneDimensionalArrayType<Type> ODARefference) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to process negative length");

  Type result = 0;
  Type sum = 0;

  for (int iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++) {
    
    if (isOdd(ODARefference.oneDimensionalArray[iterator]))
      sum += ODARefference.oneDimensionalArray[iterator];
    else 
      sum = 0;

    result = getMaximumValue (result, sum);

    if (sum < 0)
      sum = 0;
  }

  return result;
}

template<class Type> Type maximumSumSequence::getMaximumSumSequenceOfEvenNumbersODA (oneDimensionalArrayType<Type> ODARefference) {
  
  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to process negative length");

  Type result = 0;
  Type sum = 0;

  for (int iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++) {
    
    if (isEven(ODARefference.oneDimensionalArray[iterator]))
      sum += ODARefference.oneDimensionalArray[iterator];
    else  
      sum = 0;

    result = getMaximumValue (result, sum);

    if (sum < 0)
      sum = 0;
  }

  return result;
}

template <class Type> Type maximumSumSequence::getMaximumSumByParity (oneDimensionalArrayType<Type> ODARefference) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to process negative length");

  int maxOne = 0;
  int maxTwo = 0; 
  int maxSum = 0;
  
  maxOne = getMaximumSumSequenceOfOddNumbersODA (ODARefference);
  maxTwo = getMaximumSumSequenceOfEvenNumbersODA (ODARefference);

  maxSum = getMaximumValue (maxOne, maxTwo);

  return maxSum;
}

int main(int argc, char const *argv[]) {

  inputOutputOperations io;
  oneDimensionalArrayType<int> ODAObject;
  maximumSumSequence SumSequenceCore;

  auto start = high_resolution_clock::now();

  io.readOneDimensionalArray<int> ((char*)"ODA.data", ODAObject);
  io.outputOneDimensionalArray<int> (ODAObject);

  std::cout << SumSequenceCore.getMaximumSumByParity (ODAObject);

  std::cout << '\n' << '\n';

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
