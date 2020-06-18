#include "maxPalindromeDef.hpp"

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

template <class Type> bool validationRules::areEqual (Type parameterOne, Type parameterTwo) {

  if (parameterOne == parameterTwo) return true;

  return false;
}

template <class Type> void inputOutputOperations::readFileOneDimensionalArray (char * fileName, oneDimensionalArrayType<Type> ODARefference) {

  std::ifstream stream (fileName, std::ios::in);
  
  Type value;
  int iterator = 0;

  if (stream.is_open()) {

    while (stream >> value) {
      
      ODARefference.oneDimensionalArray[iterator] = value;
      iterator += 1;
    }

    stream.close();
  }

  ODARefference.length = iterator;
}

template <class Type> void inputOutputOperations::outputOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to handle length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to handle negative length");

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++)
      std::cout << ODARefference.oneDimensionalArray[iterator] << " ";

  std::cout << '\n' << '\n';
}

bool mathematicSupport::isPalindrome (int number) {

  if (__validations__.isNegative (number)) throw systemException ("Unable to process negative data");
  if (__validations__.isZero (number)) throw systemException ("Unable to process zero as data");

  int copyOfNumber = number;
  int reverse = 0;
  int digit = 0;

  while (copyOfNumber != 0) {

    digit = copyOfNumber % 10;
    reverse = reverse * 10 + digit;

    copyOfNumber /= 10;
  }

  return __validations__.areEqual (number, reverse);
}

int mathematicSupport::getMaxValueOf (int parameterOne, int parameterTwo) {

  if (parameterOne > parameterTwo) return parameterOne;

  return parameterTwo;
}

template <class Type> Type palindromeWorkFlow::getMaximumPalindromeValue (oneDimensionalArrayType<Type> ODARefference) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to handle length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to handle negative length");

  int result = ODARefference.oneDimensionalArray[0];

  for (int iterator = ODARefference.startPoint; iterator < ODARefference.length; iterator++)
    if (isPalindrome (ODARefference.oneDimensionalArray[iterator]))
      result = getMaxValueOf (result, ODARefference.oneDimensionalArray[iterator]);

  return result;
}

template <class Type> Type palindromeWorkFlow::reportAppearanceFrequency (oneDimensionalArrayType<Type> ODARefference, Type valueToCheck) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to handle length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to handle negative length");

  int contor = 0;

  for (int iterator = ODARefference.startPoint; iterator < ODARefference.length; iterator++)
    if (valueToCheck == ODARefference.oneDimensionalArray[iterator])
      contor += 1;

  return contor;
}

int main (int argc, char const * argv[]) {

  oneDimensionalArrayType <int> ODAObject; 
  palindromeWorkFlow workflow;
  inputOutputOperations io;

  int result;
  int frequency;

  auto start = high_resolution_clock::now();

  io.readFileOneDimensionalArray ((char*)"ODA.txt", ODAObject);
  io.outputOneDimensionalArray (ODAObject);

  result = workflow.getMaximumPalindromeValue (ODAObject);
  frequency = workflow.reportAppearanceFrequency (ODAObject, result);

  std::cout << result << " " << frequency << '\n'; 

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}