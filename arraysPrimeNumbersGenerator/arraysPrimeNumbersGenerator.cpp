/*
  arrays prime numbers generator
  Task:
    * generate one dimensional array with first n prime values
    * output one dimensional array
    * generate matrix with first n prime values
    * output matrix
*/

#include <chrono>
#include <fstream>
#include <iostream>
#include <math.h>

#ifndef STD_LENGTH
#define STD_LENGTH 1000
#endif

#ifndef MATRIX_STD_LENGTH
#define MATRIX_STD_LENGTH 100
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

template <class Type> class matrixType {
private:
  int standardSize = 0;

public:
  matrixType () {}

  int line = standardSize;
  int & lineRefference = line;
  int column = standardSize;
  int & columnRefference = column;

  int startLinePoint = standardSize;
  int endLinePoint = standardSize;
  int startColumnPoint = standardSize;
  int endColumnPoint = standardSize;

  Type matrix[MATRIX_STD_LENGTH][MATRIX_STD_LENGTH];

  virtual ~matrixType () {}
};

class portData {

public:
  portData () {}

  template <class Type> void portOneDimensionalArray (oneDimensionalArrayType<Type> ODAObjectOne, oneDimensionalArrayType<Type> ODAObjectTwo);
  template <class Type> void portMatrix(matrixType<Type> & matrixObjectOne, matrixType<Type> matrixObjectTwo);

  virtual ~portData () {}
};

template <class Type> void portData::portOneDimensionalArray (oneDimensionalArrayType<Type> ODAObjectOne, oneDimensionalArrayType<Type> ODAObjectTwo) {

  ODAObjectOne.length = ODAObjectTwo.length;
  ODAObjectOne.startPoint = ODAObjectTwo.startPoint;
  ODAObjectOne.endPoint = ODAObjectTwo.endPoint;

  for (size_t iterator = ODAObjectOne.startPoint; iterator < ODAObjectOne.length + ODAObjectOne.endPoint; iterator++)
    ODAObjectOne.oneDimensionalArray[iterator] = ODAObjectTwo.oneDimensionalArray[iterator];
}

template <class Type> void portData::portMatrix (matrixType<Type> & matrixObjectOne, matrixType<Type> matrixObjectTwo) {

  matrixObjectOne.line = matrixObjectTwo.line;
  matrixObjectOne.column = matrixObjectTwo.column;
  matrixObjectOne.startLinePoint = matrixObjectTwo.startLinePoint;
  matrixObjectOne.endLinePoint = matrixObjectOne.endLinePoint;
  matrixObjectOne.startColumnPoint = matrixObjectTwo.startColumnPoint;
  matrixObjectOne.endColumnPoint = matrixObjectOne.endColumnPoint;

  for (size_t iterator = matrixObjectOne.startLinePoint; iterator < matrixObjectOne.line + matrixObjectOne.endLinePoint; iterator++)
      for (size_t jiterator = matrixObjectOne.startColumnPoint; jiterator < matrixObjectOne.column + matrixObjectOne.endColumnPoint; jiterator++)
        matrixObjectOne.matrix[iterator][jiterator] = matrixObjectTwo.matrix[iterator][jiterator];
}

class inputOutputOperations {
private:
  validationRules __validations__;

public:
  inputOutputOperations () {}

  template <class Type> void outputOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference);
  template <class Type> void outputMatrix (matrixType<Type> & MTObject);

  virtual ~inputOutputOperations () {}
};

template <class Type> void inputOutputOperations::outputOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to handle length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to handle negative length");

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++)
    if (ODARefference.oneDimensionalArray[iterator] > 0)
      std::cout << ODARefference.oneDimensionalArray[iterator] << " ";

  std::cout << '\n';
}

template <class Type> void inputOutputOperations::outputMatrix (matrixType<Type> & MTObject) {

  if (__validations__.isZero(MTObject.lineRefference) || __validations__.isZero(MTObject.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__validations__.isNegative(MTObject.lineRefference) || __validations__.isNegative(MTObject.columnRefference)) throw systemException ("Unable to process with negative line or column");

  for (size_t iterator = MTObject.startLinePoint; iterator < MTObject.lineRefference + MTObject.endLinePoint; iterator++) {
    for (size_t jiterator = MTObject.startColumnPoint; jiterator < MTObject.columnRefference + MTObject.endColumnPoint; jiterator++)
      std::cout << MTObject.matrix[iterator][jiterator] << " ";
    std::cout << '\n';
  }
}

class arraysGenerator {
private:
  validationRules __rules__;

  bool isPrime (int number);

public:
  arraysGenerator () {}

  template <class Type> matrixType<Type> generatePrimeMatrix (int stopLimitGenerator);

  template <class Type> oneDimensionalArrayType<Type> generatePrimeOneDimensionalArray (int stopLimitGenerator);

  virtual ~arraysGenerator () {}
};

bool arraysGenerator::isPrime (int number) {

  if (number < 0) throw systemException("Unable to process negative number");
  if (number == 0) throw systemException("Unable to process number as zero");
  if (number == 2) return true;

  for (size_t iterator = 2; iterator <= number / 2; iterator++)
    if (number % iterator == 0) return false;

  return true;
}

template <class Type> matrixType<Type> arraysGenerator::generatePrimeMatrix (int stopLimitGenerator) {

  matrixType<Type> matrixRefference;

  matrixRefference.lineRefference = sqrt(stopLimitGenerator + matrixRefference.endLinePoint) + 1;
  matrixRefference.columnRefference = sqrt(stopLimitGenerator + matrixRefference.endColumnPoint) + 1;

  int runTimeCheck = 1;
  int iterator = 2;
  int line = 1, column = 1;

  while (runTimeCheck <= stopLimitGenerator) {

    if (isPrime(iterator)) {
      matrixRefference.matrix[line][column] = iterator;
      column += 1;
      runTimeCheck += 1;
    }

    if (column > sqrt(stopLimitGenerator)) {
      column = 1;
      line += 1;
    }

    iterator += 1;
}

  return matrixRefference;
}

template <class Type> oneDimensionalArrayType<Type> arraysGenerator::generatePrimeOneDimensionalArray (int stopLimitGenerator) {

  oneDimensionalArrayType<Type> ODARefference;

  int runTimeCheck = 1;
  int iterator = 2;

  ODARefference.length = stopLimitGenerator + ODARefference.endPoint + 1;

  while (runTimeCheck <= ODARefference.length) {

      if (isPrime(iterator)) {
        ODARefference.oneDimensionalArray[runTimeCheck] = iterator;
        runTimeCheck += 1;
      }
      iterator += 1;
  }

  return ODARefference;
}

int main(int argc, char const *argv[]) {

  oneDimensionalArrayType<int> ODARefference;
  matrixType<int> matrixRefference;
  arraysGenerator generator;
  inputOutputOperations io;
  portData __port__;

  int dataSize;

  std::cin >> dataSize;

  auto start = high_resolution_clock::now();

  ODARefference.startPoint = 1;
  ODARefference.endPoint = 1;

  __port__.portOneDimensionalArray(ODARefference, generator.generatePrimeOneDimensionalArray<int>(dataSize));
  io.outputOneDimensionalArray(ODARefference);

  std::cout << '\n';

  __port__.portMatrix(matrixRefference, generator.generatePrimeMatrix<int>(dataSize));

  matrixRefference.startLinePoint = 1;
  matrixRefference.startColumnPoint = 1;

  io.outputMatrix(matrixRefference);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "\n\n\nTime taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
