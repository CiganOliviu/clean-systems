#include "oneToZeroAlternationMatrixDef.hpp"

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

bool matrixProcessor::isEven (int number) {

    if (__rules__.isNegative(number)) throw systemException ("Unable to process with negative number");

    if (number % 2 == 0) return true;

    return false;
}

template <class Type> void matrixProcessor::generateAlternatedMatrix (matrixType<Type> & MTObject) {

  MTObject.columnRefference = MTObject.lineRefference;

  if (__rules__.isZero(MTObject.lineRefference) || __rules__.isZero(MTObject.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__rules__.isNegative(MTObject.lineRefference) || __rules__.isNegative(MTObject.columnRefference)) throw systemException ("Unable to process with negative line or column");

  for (size_t iterator = MTObject.startLinePoint; iterator < MTObject.lineRefference + MTObject.endLinePoint; iterator++)
    for (size_t jiterator = MTObject.startColumnPoint; jiterator < MTObject.columnRefference + MTObject.endColumnPoint; jiterator++) {
       if (isEven(iterator + jiterator)) MTObject.matrix[iterator][jiterator] = 1;
       else MTObject.matrix[iterator][jiterator] = 0;
     }
}

int main(int argc, char const *argv[]) {

  matrixProcessor processor;
  inputOutputOperations io;
  matrixType<int> matrix;

  std::cin >> matrix.lineRefference;

  auto start = high_resolution_clock::now();

  processor.generateAlternatedMatrix (matrix);
  io.putsMatrix (matrix);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
