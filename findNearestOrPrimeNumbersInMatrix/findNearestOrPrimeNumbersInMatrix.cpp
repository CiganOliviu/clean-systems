/*
nearest or fibonacci problem problem
Tasks:
  * determine if a number is prime, if it is return the number else return the nearest prime number
*/

#include <chrono>
#include <fstream>
#include <iostream>
#include <stdlib.h>

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

class inputOutputOperations {
private:
  validationRules __validations__;

public:
  inputOutputOperations () {}

  template <class Type> void readMatrix (char * fileName, matrixType<Type> & MTObject);
  template <class Type> void putsMatrix (matrixType<Type> & MTObject);

  virtual ~inputOutputOperations () {}
};

template <class Type> void inputOutputOperations::readMatrix (char * fileName, matrixType<Type> & MTObject) {

  std::ifstream dataStream(fileName, std::ios::in);

  Type data;
  char endOfLine;
  int auxColumnLength = MTObject.columnRefference;

  if (dataStream.is_open()) {

    while (dataStream >> data) {

      MTObject.matrix[MTObject.lineRefference][auxColumnLength] = data;

      auxColumnLength += 1;

      dataStream.get (endOfLine);

      if (endOfLine == '\n') {
        MTObject.lineRefference += 1;
        MTObject.columnRefference = auxColumnLength;
        auxColumnLength = 0;
      }
    }

    if (__validations__.isZero(MTObject.lineRefference) || __validations__.isZero(MTObject.columnRefference)) throw systemException ("Unable to process with line or column as zero");
    if (__validations__.isNegative(MTObject.lineRefference) || __validations__.isNegative(MTObject.columnRefference)) throw systemException ("Unable to process with negative line or column");

    dataStream.close();
  }
  else throw systemException("Unable to open file");
}

template <class Type> void inputOutputOperations::putsMatrix (matrixType<Type> & MTObject) {

  if (__validations__.isZero(MTObject.lineRefference) || __validations__.isZero(MTObject.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__validations__.isNegative(MTObject.lineRefference) || __validations__.isNegative(MTObject.columnRefference)) throw systemException ("Unable to process with negative line or column");

  for (size_t iterator = MTObject.startLinePoint; iterator < MTObject.lineRefference + MTObject.endLinePoint; iterator++) {
    for (size_t jiterator = MTObject.startColumnPoint; jiterator < MTObject.columnRefference + MTObject.endColumnPoint; jiterator++)
      std::cout << MTObject.matrix[iterator][jiterator] << " ";
    std::cout << '\n';
  }
}

class matrixWorkFlow {
private:
  validationRules __validations__;

  int returnPrimeNumber (int number);
  int minimumDifference (int argOne, int argTwo, int differenceTermen);
  int returnNearestOrPrimeNumber (int number);

public:
  matrixWorkFlow () {}

  template <class Type> void primeOrClosestPrimeValuesMatrix(matrixType<Type> & MTObject);

  virtual ~matrixWorkFlow () {}
};

int matrixWorkFlow::returnPrimeNumber (int number) {

  if (__validations__.isNegative(number)) systemException("Unable to process negative values");
  if (__validations__.isZero(number)) systemException("Unable to process number as zero");

  if (number == 2) return 2;

  for (size_t it = 2; it <= number / 2; it++)
    if (number % it == 0)
      return 0;

  return number;
}

int matrixWorkFlow::minimumDifference (int argOne, int argTwo, int differenceTermen) {

  if (abs(differenceTermen - argOne) < abs(differenceTermen - argTwo)) return argOne;

  return argTwo;
}

int matrixWorkFlow::returnNearestOrPrimeNumber (int number) {

  int underNumber, aboveNumber, closestNumber, iterator = 1;
  bool runTimeChecker = true;

  while (runTimeChecker) {

    if (returnPrimeNumber(iterator) < number && returnPrimeNumber(iterator) != 0)
      underNumber = returnPrimeNumber(iterator);
    if (returnPrimeNumber(iterator) > number && returnPrimeNumber(iterator) != 0) {
      aboveNumber = returnPrimeNumber(iterator);
      runTimeChecker = false;
    }
    if (returnPrimeNumber(iterator) == number) return number;

    iterator += 1;
  }
  closestNumber = minimumDifference (underNumber, aboveNumber, number);

  return closestNumber;
}

template <class Type> void matrixWorkFlow::primeOrClosestPrimeValuesMatrix(matrixType<Type> & MTObject) {

  if (__validations__.isZero(MTObject.lineRefference) || __validations__.isZero(MTObject.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__validations__.isNegative(MTObject.lineRefference) || __validations__.isNegative(MTObject.columnRefference)) throw systemException ("Unable to process with negative line or column");

  for (size_t iterator = MTObject.startLinePoint; iterator < MTObject.lineRefference + MTObject.endLinePoint; iterator++)
    for (size_t jiterator = MTObject.startColumnPoint; jiterator < MTObject.columnRefference + MTObject.endColumnPoint; jiterator++)
      MTObject.matrix[iterator][jiterator] = returnNearestOrPrimeNumber(MTObject.matrix[iterator][jiterator]);
}

int main(int argc, char const *argv[]) {

  matrixWorkFlow __initializeProcessor__;
  inputOutputOperations io;
  matrixType<int> MTRefference;

  auto start = high_resolution_clock::now();

  io.readMatrix ((char*)"matrix.data", MTRefference);
  io.putsMatrix (MTRefference);
  __initializeProcessor__.primeOrClosestPrimeValuesMatrix (MTRefference);
  std::cout << '\n';
  io.putsMatrix (MTRefference);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "\n\n\nTime taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
