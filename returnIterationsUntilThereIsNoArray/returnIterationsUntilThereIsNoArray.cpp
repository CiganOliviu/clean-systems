#include "returnIterationsUntilThereIsNoArrayDef.hpp"

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

bool oneDimensionalArrayProcesses::isPrime (int number) {

  if (__validations__.isNegative(number)) throw systemException("Unable to process negative value");

  if (number == 0) return false;

  if (number == 2) return true;

  for (size_t iterator = 2; iterator <= number / 2; iterator++)
    if (number % iterator == 0) return false;

  return true;
}

template <class Type> bool oneDimensionalArrayProcesses::arrayValidation (oneDimensionalArrayType<Type> ODARefference) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to process negative length");

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++)
    if (ODARefference.oneDimensionalArray[iterator] != 0) return true;

  return false;
}

template <class Type> int oneDimensionalArrayProcesses::returnIterationsOverArray (oneDimensionalArrayType<Type> ODARefference) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to process negative length");

  int contor = 0;

  while (arrayValidation(ODARefference)) {

    for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length; iterator++)
      if (isPrime(ODARefference.oneDimensionalArray[iterator])) {
        ODARefference.oneDimensionalArray[iterator] = 0;
        contor += 1;
      }
      else if (ODARefference.oneDimensionalArray[iterator] != 0)
        ODARefference.oneDimensionalArray[iterator] += 1;
    }

  return contor;
}

int main(int argc, char const *argv[]) {

  oneDimensionalArrayType<int> ODAObject;
  inputOutputOperations io;
  oneDimensionalArrayProcesses ODAProcesses;

  auto start = high_resolution_clock::now();

  io.readOneDimensionalArray<int> ((char*)"ODA.data", ODAObject);
  io.outputOneDimensionalArray<int> (ODAObject);

  std::cout << ODAProcesses.returnIterationsOverArray (ODAObject) << '\n';

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
