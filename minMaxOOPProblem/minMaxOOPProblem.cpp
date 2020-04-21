#include "minMaxOOPProblemDef.hpp"

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
}

template <class Type> Type minMaxWorkFlow::maximOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference) {

  int maxim = ODARefference.oneDimensionalArray[0];

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to handle length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to handle negative length");

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++)
    if (maxim < ODARefference.oneDimensionalArray[iterator])
      maxim = ODARefference.oneDimensionalArray[iterator];

  return maxim;
}

template <class Type> Type minMaxWorkFlow::minimOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference) {

  int minim = ODARefference.oneDimensionalArray[0];

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to handle length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to handle negative length");

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++)
    if (minim > ODARefference.oneDimensionalArray[iterator])
      minim = ODARefference.oneDimensionalArray[iterator];

  return minim;
}

template <class Type> void minMaxWorkFlow::interchangeValues (Type * parameterOne, Type * parameterTwo) {

  *parameterOne = *parameterOne + *parameterTwo;
  *parameterTwo = *parameterOne - *parameterTwo;
  *parameterOne = *parameterOne - *parameterTwo;
}

template <class Type> void minMaxWorkFlow::interchangeMaxMin (oneDimensionalArrayType<Type> ODARefference) {

  int maxim = maximOneDimensionalArray (ODARefference);
  int minim = minimOneDimensionalArray (ODARefference);
  int posMax, posMin;

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to handle length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to handle negative length");

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++) {
    if (maxim == ODARefference.oneDimensionalArray[iterator]) posMax = iterator;
    if (minim == ODARefference.oneDimensionalArray[iterator]) posMin = iterator;
  }

  interchangeValues(&ODARefference.oneDimensionalArray[posMax], &ODARefference.oneDimensionalArray[posMin]);
}

int main(int argc, char const *argv[]) {

  minMaxWorkFlow minMaxRefference;
  oneDimensionalArrayType <int> ODARefference;
  inputOutputOperations io;

  auto start = high_resolution_clock::now();

  io.readOneDimensionalArray ((char*)"ODA.data", ODARefference);
  io.outputOneDimensionalArray (ODARefference);
  std::cout << '\n';
  std::cout << minMaxRefference.minimOneDimensionalArray (ODARefference);
  std::cout << '\n';
  std::cout << minMaxRefference.maximOneDimensionalArray (ODARefference);
  minMaxRefference.interchangeMaxMin (ODARefference);
  std::cout << '\n';
  io.outputOneDimensionalArray (ODARefference);
  std::cout << '\n';

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
