#include "sumOfEvenDigitsDef.hpp"

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

template <class Type> void portData::portOneDimensionalArray (oneDimensionalArrayType<Type> ODAObjectOne, oneDimensionalArrayType<Type> ODAObjectTwo) {

  ODAObjectOne.length = ODAObjectTwo.length;
  ODAObjectOne.startPoint = ODAObjectTwo.startPoint;
  ODAObjectOne.endPoint = ODAObjectTwo.endPoint;

  for (size_t iterator = ODAObjectOne.startPoint; iterator < ODAObjectOne.length + ODAObjectOne.endPoint; iterator++)
    ODAObjectOne.oneDimensionalArray[iterator] = ODAObjectTwo.oneDimensionalArray[iterator];
}

template <class Type> Type inputOutputOperations::readNumber () {
  
  Type NumberForIO;

  std::cin >> NumberForIO;

  return NumberForIO;
}

template <class Type> void inputOutputOperations::outputOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to handle length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to handle negative length");

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++)
    if (ODARefference.oneDimensionalArray[iterator] > 0)
      std::cout << ODARefference.oneDimensionalArray[iterator] << " ";

  std::cout << '\n';
}

template<class Type> bool dataProcessor::isEven (Type parameter) {
  
  if (__validations__.isNegative(parameter)) throw systemException ("Unable to process negative data");

  if (parameter % 2 == 0) return true;

  return false;
}

template <class Type> oneDimensionalArrayType<int> dataProcessor::saveAppearanceFrequencyArray (Type parameter) {
  
  oneDimensionalArrayType<int> frequencyODA;
  frequencyODA.length = 9;

  Type digit;

  while (parameter > 10) {

    digit = parameter % 10;

    if (isEven(digit)) {
      frequencyODA.oneDimensionalArray[digit] = 1;
    }

    parameter /= 10;
  }

  return frequencyODA;  
}

template <class Type> Type dataProcessor::getSumOfEvenDigits (oneDimensionalArrayType<Type> ODARefference) {
  
  int result = 0;

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to handle length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to handle negative length");

  for (size_t iterator = ODARefference.startPoint; iterator <= 9; iterator++)
    if (ODARefference.oneDimensionalArray[iterator] == 1)
      result += iterator;

  return result;
}

int main (int argc, char const * argv[]) {

  inputOutputOperations ioSystem;
  portData portSystem;
  oneDimensionalArrayType<int> frequencyODA;
  dataProcessor processorSystem;

  int number;
  int result;

  number = ioSystem.readNumber<int> ();

  auto start = high_resolution_clock::now();

  portSystem.portOneDimensionalArray(frequencyODA, processorSystem.saveAppearanceFrequencyArray (number));  

  result = processorSystem.getSumOfEvenDigits<int> (frequencyODA); 

  std::cout << result << '\n' << '\n';

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}