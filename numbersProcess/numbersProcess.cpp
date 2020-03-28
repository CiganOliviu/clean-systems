/*
  numbers process
  Tasks:
    * read one dimensional array
    * output one dimensional array
    * remove the duplications and sort every number
    * print out the frequency of every number that appears in array
*/

#include <chrono>
#include <fstream>
#include <iostream>

#ifndef STD_LENGTH
#define STD_LENGTH 1000
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

class portData {

public:
  portData () {}

  template <class Type> void portOneDimensionalArray (oneDimensionalArrayType<Type> ODAObjectOne, oneDimensionalArrayType<Type> ODAObjectTwo);

  virtual ~portData () {}
};

template <class Type> void portData::portOneDimensionalArray (oneDimensionalArrayType<Type> ODAObjectOne, oneDimensionalArrayType<Type> ODAObjectTwo) {

  ODAObjectOne.length = ODAObjectTwo.length;
  ODAObjectOne.startPoint = ODAObjectTwo.startPoint;
  ODAObjectOne.endPoint = ODAObjectTwo.endPoint;

  for (size_t iterator = ODAObjectOne.startPoint; iterator < ODAObjectOne.length + ODAObjectOne.endPoint; iterator++)
    ODAObjectOne.oneDimensionalArray[iterator] = ODAObjectTwo.oneDimensionalArray[iterator];
}

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

class numberProcess {
private:
  validationRules __validations__;

  template <class Type> Type sortAndNormalizeNumber (Type parameter);

public:
  numberProcess () {};

  template <class Type> void normalizeOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference);
  template <class Type> oneDimensionalArrayType<int> frequencyNumbersAppereances (oneDimensionalArrayType<Type> ODARefference);

  virtual ~numberProcess () {}
};

template <class Type> Type numberProcess::sortAndNormalizeNumber (Type parameter) {

  Type parameterRefference, returnResult = 0;
  bool validationRunTime = true;

  parameterRefference = parameter;

  for (Type iterator = 9; iterator >= 0; iterator--) {

    while (parameterRefference != 0 && validationRunTime) {

      if (parameterRefference % 10 == iterator) {

        returnResult = returnResult * 10 + iterator;
        validationRunTime = false;
      }

      parameterRefference /= 10;
    }

    validationRunTime = true;
    parameterRefference = parameter;
  }

  return returnResult;
}

template <class Type> void numberProcess::normalizeOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to handle length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to handle negative length");

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++)
    ODARefference.oneDimensionalArray[iterator] = sortAndNormalizeNumber (ODARefference.oneDimensionalArray[iterator]);
}

template <class Type> oneDimensionalArrayType<int> numberProcess::frequencyNumbersAppereances (oneDimensionalArrayType<Type> ODARefference) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to handle length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to handle negative length");

  oneDimensionalArrayType<int> frequencyODA;
  int frequency = 0;

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++) {
    for (size_t jiterator = ODARefference.startPoint; jiterator < ODARefference.length + ODARefference.endPoint; jiterator++)
      if (ODARefference.oneDimensionalArray[iterator] == ODARefference.oneDimensionalArray[jiterator])
        frequency += 1;

    if (ODARefference.oneDimensionalArray[iterator - 1] != ODARefference.oneDimensionalArray[iterator]) {
      frequencyODA.oneDimensionalArray[frequencyODA.length] = frequency;
      frequencyODA.length += 1;
    }
    frequency = 0;
  }

  return frequencyODA;
}

int main(int argc, char const *argv[]) {

  auto start = high_resolution_clock::now();

  numberProcess processDataInitialization;
  portData initializePortData;
  inputOutputOperations io;
  oneDimensionalArrayType<int> ODARefference;
  oneDimensionalArrayType<int> frequencyODA;

  io.readOneDimensionalArray ((char*)"ODA.data", ODARefference);
  io.outputOneDimensionalArray (ODARefference);
  processDataInitialization.normalizeOneDimensionalArray (ODARefference);
  io.outputOneDimensionalArray (ODARefference);
  initializePortData.portOneDimensionalArray (frequencyODA, processDataInitialization.frequencyNumbersAppereances (ODARefference));
  io.outputOneDimensionalArray (frequencyODA);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "\n\n\nTime taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
