#include "combineTwoMatricesDef.hpp"

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

template <class Type> void portData::portMatrices (matrixType<Type> & matrixObjectOne, matrixType<Type> matrixObjectTwo) {

  if (__rules__.isZero(matrixObjectTwo.lineRefference) || __rules__.isZero(matrixObjectTwo.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__rules__.isNegative(matrixObjectTwo.lineRefference) || __rules__.isNegative(matrixObjectTwo.columnRefference)) throw systemException ("Unable to process with negative line or column");

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

    if (__rules__.isZero(MTObject.lineRefference) || __rules__.isZero(MTObject.columnRefference)) throw systemException ("Unable to process with line or column as zero");
    if (__rules__.isNegative(MTObject.lineRefference) || __rules__.isNegative(MTObject.columnRefference)) throw systemException ("Unable to process with negative line or column");

    dataStream.close();
  }
  else throw systemException("Unable to open file");
}

template <class Type> void inputOutputOperations::putsMatrix (matrixType<Type> & MTObject) {

  if (__rules__.isZero(MTObject.lineRefference) || __rules__.isZero(MTObject.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__rules__.isNegative(MTObject.lineRefference) || __rules__.isNegative(MTObject.columnRefference)) throw systemException ("Unable to process with negative line or column");

  for (size_t iterator = MTObject.startLinePoint; iterator < MTObject.lineRefference + MTObject.endLinePoint; iterator++) {
    for (size_t jiterator = MTObject.startColumnPoint; jiterator < MTObject.columnRefference + MTObject.endColumnPoint; jiterator++)
      std::cout << MTObject.matrix[iterator][jiterator] << " ";
    std::cout << '\n';
  }
}

template <class Type> Type matricesCombinerBasedOnConditions::getMinOfTwoNumbers (Type parameterOne, Type parameterTwo) {
  
  if (parameterOne < parameterTwo) return parameterOne;
  
  return parameterTwo;
}

template <class Type> matrixType<Type> matricesCombinerBasedOnConditions::combineMatrices (matrixType<Type> MTObjectOne, matrixType<Type> MTObjectTwo) {
  
  if (__rules__.isZero(MTObjectOne.lineRefference) || __rules__.isZero(MTObjectOne.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__rules__.isNegative(MTObjectOne.lineRefference) || __rules__.isNegative(MTObjectOne.columnRefference)) throw systemException ("Unable to process with negative line or column");

  if (__rules__.isZero(MTObjectTwo.lineRefference) || __rules__.isZero(MTObjectTwo.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__rules__.isNegative(MTObjectTwo.lineRefference) || __rules__.isNegative(MTObjectTwo.columnRefference)) throw systemException ("Unable to process with negative line or column");

  matrixType<Type> resultMatrix;

  resultMatrix.lineRefference = MTObjectOne.lineRefference;
  resultMatrix.columnRefference = MTObjectOne.columnRefference;

  for (size_t iterator = MTObjectOne.startLinePoint; iterator < MTObjectOne.lineRefference + MTObjectOne.endLinePoint; iterator++) {
    for (size_t jiterator = MTObjectOne.startColumnPoint; jiterator < MTObjectOne.columnRefference + MTObjectOne.endColumnPoint; jiterator++) {
      if (iterator < jiterator) resultMatrix.matrix[iterator][jiterator] = MTObjectOne.matrix[iterator][jiterator];
      if (iterator == jiterator) resultMatrix.matrix[iterator][jiterator] = getMinOfTwoNumbers (MTObjectOne.matrix[iterator][jiterator], MTObjectTwo.matrix[iterator][jiterator]);
      if (iterator > jiterator) resultMatrix.matrix[iterator][jiterator] = MTObjectTwo.matrix[iterator][jiterator];
    }
  }

  return resultMatrix;
}

template <class Type> matrixType<Type> combineMatrices (matrixType<Type> MTObjectOne, matrixType<Type> MTObjectTwo);

int main(int argc, char const *argv[]) {

  matrixType<int> matrixA;
  matrixType<int> matrixB;
  matrixType<int> matrixC;
  portData port;
  inputOutputOperations IOSys;  
  matricesCombinerBasedOnConditions matricesCombiner;

  auto start = high_resolution_clock::now();

  IOSys.readMatrix ((char*)"MatrixA.txt", matrixA);
  IOSys.readMatrix ((char*)"MatrixB.txt", matrixB);

  port.portMatrices (matrixC, matricesCombiner.combineMatrices (matrixA, matrixB));

  IOSys.putsMatrix (matrixC);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "\n\n\nTime taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
