#include "generateMatrixBasedOnConditionsDef.hpp"

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

template <class Type> bool matrixGeneratorBasedOnConditions::isLineZero (matrixType<Type> MTObject, int line) {

  if (__rules__.isZero(MTObject.lineRefference) || __rules__.isZero(MTObject.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__rules__.isNegative(MTObject.lineRefference) || __rules__.isNegative(MTObject.columnRefference)) throw systemException ("Unable to process with negative line or column");

  line -= 1;

  for (size_t iterator = line; iterator < line + 1; iterator++)
    for (size_t jiterator = MTObject.startColumnPoint; jiterator < MTObject.columnRefference + MTObject.endColumnPoint; jiterator++)
      if (MTObject.matrix[iterator][jiterator] != 0) return false;

  return true;
}

template <class Type> int matrixGeneratorBasedOnConditions::sumOfColumn (matrixType<Type> MTObject, int column) {

  if (__rules__.isZero(MTObject.lineRefference) || __rules__.isZero(MTObject.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__rules__.isNegative(MTObject.lineRefference) || __rules__.isNegative(MTObject.columnRefference)) throw systemException ("Unable to process with negative line or column");

  int sum = 0;
  column -= 1;

  for (size_t iterator = MTObject.startColumnPoint; iterator < MTObject.columnRefference + MTObject.endColumnPoint; iterator++)
      for (size_t jiterator = column; jiterator < column + 1; jiterator++)
        sum += MTObject.matrix[iterator][jiterator];

  return sum;
}

template <class Type> matrixType<Type> matrixGeneratorBasedOnConditions::modifyMatrix (matrixType<Type> MTObject) {

  if (__rules__.isZero(MTObject.lineRefference) || __rules__.isZero(MTObject.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__rules__.isNegative(MTObject.lineRefference) || __rules__.isNegative(MTObject.columnRefference)) throw systemException ("Unable to process with negative line or column");

  matrixType<Type> generatedMatrixObject;

  __port__.portMatrices(generatedMatrixObject, MTObject);

  int iterator = 1;

  while (iterator <= MTObject.lineRefference) {

    if (isLineZero(MTObject, iterator))
      for (size_t jiterator = MTObject.startLinePoint; jiterator < MTObject.lineRefference; jiterator++)
        generatedMatrixObject.matrix[iterator - 1][jiterator] = sumOfColumn (MTObject, jiterator + 1);

    iterator += 1;
  }

  return generatedMatrixObject;
}

int main(int argc, char const *argv[]) {

  matrixType<int> MTRefference, generatedMTRefference;
  matrixGeneratorBasedOnConditions __matrixGeneratorInit__;
  inputOutputOperations io;
  portData __port__;

  auto start = high_resolution_clock::now();

  io.readMatrix ((char*)"matrix.data", MTRefference);
  io.putsMatrix (MTRefference);
  __port__.portMatrices(generatedMTRefference, __matrixGeneratorInit__.modifyMatrix (MTRefference));
  std::cout << '\n';
  io.putsMatrix (generatedMTRefference);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "\n\n\nTime taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
