/*
  Sort in parts one dimensional array
  Tasks:
    * read one dimensional array from a file
    * print one dimensional array with the new values
    * sort the prime values to the left and the rest to the right
*/

#include <chrono>
#include <fstream>
#include <iostream>

#ifndef STD_LENGTH
#define STD_LENGTH 100000
#endif

using namespace std::chrono;

class systemException : public std::exception {
private:
  std::string processMessage;

public:
  systemException (std::string errorMessage) : processMessage(errorMessage) {}

  const char * what () const throw ();

  virtual ~systemException () throw () {}
};

const char * systemException::what () const throw () {

  return processMessage.c_str();
}

class validationRules {

public:
  validationRules () {}

  template <class Type> bool isNegative (Type parameter);
  template <class Type> bool isZero (Type parameter);

  virtual ~validationRules () {}
};

template <class Type> bool validationRules::isNegative (Type parameter) {

  if (parameter < 0) return true;

  return false;
}

template <class Type> bool validationRules::isZero (Type parameter) {

  if (parameter == 0) return true;

  return false;
}

template <class Type> class oneDimensionalArrayType {
private:
  int standardSize = 0;

public:
  oneDimensionalArrayType () {}

  int & length = standardSize;
  int startPoint = standardSize;
  int endPoint = standardSize;

  Type * oneDimensionalArray = new Type[STD_LENGTH];

  virtual ~oneDimensionalArrayType () {}
};

class inputOutputOperations {
private:
  validationRules __validations__;

public:
  inputOutputOperations () {}

  template <class Type> void readOneDimensionalArray (char * fileName, oneDimensionalArrayType<Type> ODARefference);
  template <class Type> void outputOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference);

  virtual ~inputOutputOperations () {}
};

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

class oneDimensionalArrayProcesses {
private:
  validationRules __validations__;

  template <class Type> inline void interchangeValues (Type * parameterOne, Type * parameterTwo);
  bool isPrime (int number);

public:
  oneDimensionalArrayProcesses () {}

  template <class Type> void sortPrimeValuesFromOneDimensionalArray (oneDimensionalArrayType<Type> ODAObject);
  template <class Type> void sortNonePrimeValuesFromOneDimensionalArray (oneDimensionalArrayType<Type> ODAObject);

  virtual ~oneDimensionalArrayProcesses () {}
};

template <class Type> void oneDimensionalArrayProcesses::interchangeValues (Type * parameterOne, Type * parameterTwo) {

  *parameterOne = *parameterOne + *parameterTwo;
  *parameterTwo = *parameterOne - *parameterTwo;
  *parameterOne = *parameterOne - *parameterTwo;
}

bool oneDimensionalArrayProcesses::isPrime (int number) {

  if (__validations__.isNegative(number)) throw systemException("Unable to process negative value");
  if (__validations__.isZero(number)) throw systemException("Unable to process a value as zero");

  if (number == 2) return true;

  for (size_t iterator = 2; iterator <= number / 2; iterator++)
    if (number % iterator == 0) return false;

  return true;
}

template <class Type> void oneDimensionalArrayProcesses::sortPrimeValuesFromOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to process negative length");

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint - 1; iterator++)
      for (size_t jiterator = ODARefference.startPoint; jiterator < ODARefference.length + ODARefference.endPoint - iterator - 1; jiterator++)
        if (isPrime(ODARefference.oneDimensionalArray[jiterator]) && isPrime(ODARefference.oneDimensionalArray[jiterator + 1]))
          if (ODARefference.oneDimensionalArray[jiterator] > ODARefference.oneDimensionalArray[jiterator + 1])
            interchangeValues (&ODARefference.oneDimensionalArray[jiterator], &ODARefference.oneDimensionalArray[jiterator + 1]);
}

template <class Type> void oneDimensionalArrayProcesses::sortNonePrimeValuesFromOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to process negative length");

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint - 1; iterator++)
      for (size_t jiterator = ODARefference.startPoint; jiterator < ODARefference.length + ODARefference.endPoint - iterator - 1; jiterator++)
        if (!isPrime(ODARefference.oneDimensionalArray[jiterator]) && !isPrime(ODARefference.oneDimensionalArray[jiterator + 1]))
          if (ODARefference.oneDimensionalArray[jiterator] > ODARefference.oneDimensionalArray[jiterator + 1])
            interchangeValues (&ODARefference.oneDimensionalArray[jiterator], &ODARefference.oneDimensionalArray[jiterator + 1]);
}

int main(int argc, char const *argv[]) {

  oneDimensionalArrayType<int> ODAObject;
  inputOutputOperations io;
  oneDimensionalArrayProcesses ODAProcesses;

  auto start = high_resolution_clock::now();

  io.readOneDimensionalArray<int> ((char*)"ODA.data", ODAObject);
  io.outputOneDimensionalArray<int> (ODAObject);
  ODAProcesses.sortPrimeValuesFromOneDimensionalArray(ODAObject);
  ODAProcesses.sortNonePrimeValuesFromOneDimensionalArray(ODAObject);
  io.outputOneDimensionalArray<int> (ODAObject);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
