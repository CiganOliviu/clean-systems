#include "matrixProcessProblemDef.hpp"

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

template <class Type> bool dataProcessor::isPrime (Type parameter) {

  if (parameter <= 0) return false;
  if (parameter == 2) return true;

  for (size_t iterator = 2; iterator <= parameter / 2; iterator++)
    if (parameter % iterator == 0) return false;

  return true;
}

template <class Type> void dataProcessor::interchangeValues (Type * parameterOne, Type * parameterTwo) {

  * parameterOne = * parameterOne + * parameterTwo;
  * parameterTwo = * parameterOne - * parameterTwo;
  * parameterOne = * parameterOne - * parameterTwo;
}

template <class Type> void dataProcessor::readMatrix (char * fileName, matrixType<Type> & MTObject) {

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

    if (__rules__.isZero(MTObject.lineRefference) || __rules__.isZero(MTObject.columnRefference)) throw systemException ("Unable to process with line or column as zero");
    if (__rules__.isNegative(MTObject.lineRefference) || __rules__.isNegative(MTObject.columnRefference)) throw systemException ("Unable to process with negative line or column");

    dataStream.close();
  }
  else throw systemException("Unable to open file");
}

template <class Type> void dataProcessor::putsMatrix (matrixType<Type> & MTObject) {

  if (__rules__.isZero(MTObject.lineRefference) || __rules__.isZero(MTObject.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__rules__.isNegative(MTObject.lineRefference) || __rules__.isNegative(MTObject.columnRefference)) throw systemException ("Unable to process with negative line or column");

  for (size_t iterator = MTObject.startLinePoint; iterator < MTObject.lineRefference + MTObject.endLinePoint; iterator++) {
    for (size_t jiterator = MTObject.startColumnPoint; jiterator < MTObject.columnRefference + MTObject.endColumnPoint; jiterator++)
      std::cout << MTObject.matrix[iterator][jiterator] << " ";
    std::cout << '\n';
  }
}

template <class Type> void dataProcessor::primeValuesFromMainDiagonal (matrixType<Type> & MTObject) {

  if (__rules__.isZero(MTObject.lineRefference) || __rules__.isZero(MTObject.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__rules__.isNegative(MTObject.lineRefference) || __rules__.isNegative(MTObject.columnRefference)) throw systemException ("Unable to process with negative line or column");

  for (size_t iterator = MTObject.startLinePoint; iterator < MTObject.lineRefference + MTObject.endLinePoint; iterator++)
    for (size_t jiterator = MTObject.startColumnPoint; jiterator < MTObject.columnRefference + MTObject.endColumnPoint; jiterator++)
      if (iterator == jiterator)
        if (isPrime(MTObject.matrix[iterator][jiterator])) std::cout << MTObject.matrix[iterator][jiterator] << " ";
  std::cout << '\n';
}

template <class Type> void dataProcessor::paralelValuesWithMD (matrixType<Type> & MTObject) {

  if (__rules__.isZero(MTObject.lineRefference) || __rules__.isZero(MTObject.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__rules__.isNegative(MTObject.lineRefference) || __rules__.isNegative(MTObject.columnRefference)) throw systemException ("Unable to process with negative line or column");

  int order;

  std::cin >> order;

  if (__rules__.isZero(order)) throw systemException ("Unable to process with order as zero");

  for (int iterator = MTObject.startLinePoint; iterator < MTObject.lineRefference + MTObject.endLinePoint; iterator++)
    for (int jiterator = MTObject.startColumnPoint; jiterator < MTObject.columnRefference + MTObject.endColumnPoint; jiterator++)
      if (abs(iterator - jiterator) == order) std::cout << MTObject.matrix[iterator][jiterator] << " ";
  std::cout << '\n';
}

template <class Type> void dataProcessor::paralelValuesWithSD (matrixType<Type> & MTObject) {

  if (__rules__.isZero(MTObject.lineRefference) || __rules__.isZero(MTObject.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__rules__.isNegative(MTObject.lineRefference) || __rules__.isNegative(MTObject.columnRefference)) throw systemException ("Unable to process with negative line or column");

  int order;

  std::cin >> order;

  if (__rules__.isZero(order)) throw systemException ("Unable to process with order as zero");

  for (int iterator = MTObject.startLinePoint; iterator < MTObject.lineRefference + MTObject.endLinePoint; iterator++)
    for (int jiterator = MTObject.startColumnPoint; jiterator < MTObject.columnRefference + MTObject.endColumnPoint; jiterator++)
      if (abs(iterator + jiterator - MTObject.line + 1) == order) std::cout << MTObject.matrix[iterator][jiterator] << " ";
  std::cout << '\n';
}

template <class Type> void dataProcessor::matrixTransposition (matrixType<Type> & MTObject) {

  if (__rules__.isZero(MTObject.lineRefference) || __rules__.isZero(MTObject.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__rules__.isNegative(MTObject.lineRefference) || __rules__.isNegative(MTObject.columnRefference)) throw systemException ("Unable to process with negative line or column");

  for (size_t iterator = MTObject.startLinePoint; iterator < MTObject.lineRefference + MTObject.endLinePoint; iterator++) {
    for (size_t jiterator = MTObject.startColumnPoint; jiterator < MTObject.columnRefference + MTObject.endColumnPoint; jiterator++)
      std::cout << MTObject.matrix[jiterator][iterator] << " ";
    std::cout << '\n';
  }
}

int main(int argc, char const *argv[]) {

  dataProcessor __initializeProcessor__;
  matrixType<int> MTRefference;

  auto start = high_resolution_clock::now();

  __initializeProcessor__.readMatrix ((char*)"matrix.data", MTRefference);
  __initializeProcessor__.putsMatrix (MTRefference);
  std::cout << '\n';
  __initializeProcessor__.primeValuesFromMainDiagonal (MTRefference);
  std::cout << '\n';
  __initializeProcessor__.paralelValuesWithMD (MTRefference);
  std::cout << '\n';
  __initializeProcessor__.paralelValuesWithSD (MTRefference);
  std::cout << '\n';
  __initializeProcessor__.matrixTransposition (MTRefference);
  std::cout << '\n';
  __initializeProcessor__.putsMatrix (MTRefference);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "\n\n\nTime taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
