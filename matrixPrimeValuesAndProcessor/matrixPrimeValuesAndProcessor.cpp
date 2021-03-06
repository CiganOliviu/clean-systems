#include "matrixPrimeValuesAndProcessorDef.hpp"

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

template <class Type> void inputOutputOperations::outputMatrix (matrixType<Type> & MTObject) {

  if (__validations__.isZero(MTObject.lineRefference) || __validations__.isZero(MTObject.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__validations__.isNegative(MTObject.lineRefference) || __validations__.isNegative(MTObject.columnRefference)) throw systemException ("Unable to process with negative line or column");

  for (size_t iterator = MTObject.startLinePoint; iterator < MTObject.lineRefference + MTObject.endLinePoint; iterator++) {
    for (size_t jiterator = MTObject.startColumnPoint; jiterator < MTObject.columnRefference + MTObject.endColumnPoint; jiterator++)
      std::cout << MTObject.matrix[iterator][jiterator] << " ";
    std::cout << '\n';
  }
}

bool dataProcessor::isPrime(int number) {

  if (number == 2) return true;

  for (size_t iterator = 2; iterator <= number / 2; iterator++)
    if (number % iterator == 0) return false;

  return true;
}

int dataProcessor::the_N_primeValue (int number) {

  int index = 2;
  int the_N_value = 0;

  while (number > 0) {

    if (isPrime(index)) {
      the_N_value = index;
      number -= 1;
    }

    index += 1;
  }

  return the_N_value;
}

bool dataProcessor::isOdd (int number) {

  if (number % 2 == 1) return true;

  return false;
}

bool dataProcessor::isEven (int number) {

  if (number % 2 == 0) return true;

  return false;
}

template <class Type> void dataProcessor::getValuesOddMatrix (matrixType<Type> MTObject) {

  if (__rules__.isZero(MTObject.lineRefference) || __rules__.isZero(MTObject.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__rules__.isNegative(MTObject.lineRefference) || __rules__.isNegative(MTObject.columnRefference)) throw systemException ("Unable to process with negative line or column");

  std::cout << MTObject.matrix[MTObject.lineRefference / 2][MTObject.columnRefference / 2] << " ";
  std::cout << MTObject.matrix[MTObject.lineRefference / 2 + 1][MTObject.columnRefference / 2 - 1] << " ";
  std::cout << MTObject.matrix[MTObject.lineRefference / 2 - 1][MTObject.columnRefference / 2 + 1] << " ";
  std::cout << MTObject.matrix[MTObject.lineRefference / 2 - 1][MTObject.columnRefference / 2 - 1] << " ";
  std::cout << MTObject.matrix[MTObject.lineRefference / 2 + 1][MTObject.columnRefference / 2 + 1] << " ";
}

template <class Type> void dataProcessor::getValuesEvenMatrix (matrixType<Type> MTObject) {

  if (__rules__.isZero(MTObject.lineRefference) || __rules__.isZero(MTObject.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__rules__.isNegative(MTObject.lineRefference) || __rules__.isNegative(MTObject.columnRefference)) throw systemException ("Unable to process with negative line or column");

  for (size_t iterator = MTObject.startLinePoint + 1; iterator < MTObject.lineRefference + MTObject.endLinePoint - 1; iterator++)
    for (size_t jiterator = MTObject.startColumnPoint + 1; jiterator < MTObject.columnRefference + MTObject.endColumnPoint - 1; jiterator++)
      std::cout << MTObject.matrix[iterator][jiterator] << " ";
}

template <class Type> void dataProcessor::generateMatrix (matrixType<Type> & MTObject) {

  if (__rules__.isZero(MTObject.lineRefference) || __rules__.isZero(MTObject.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__rules__.isNegative(MTObject.lineRefference) || __rules__.isNegative(MTObject.columnRefference)) throw systemException ("Unable to process with negative line or column");

  int index = 1;

  for (size_t iterator = MTObject.startLinePoint; iterator < MTObject.lineRefference + MTObject.endLinePoint; iterator++)
    for (size_t jiterator = MTObject.startColumnPoint; jiterator < MTObject.columnRefference + MTObject.endColumnPoint; jiterator++) {
      MTObject.matrix[iterator][jiterator] = the_N_primeValue (index);
      index += 1;
    }
}

template <class Type> void dataProcessor::processSpecificMatrix (matrixType<Type> MTObject) {

  if (isOdd(MTObject.lineRefference))
    getValuesOddMatrix(MTObject);

  else if (isEven(MTObject.lineRefference))
    getValuesEvenMatrix(MTObject);
}

int main(int argc, char const *argv[]) {

  dataProcessor __initializeProcessor__;
  inputOutputOperations io;
  matrixType<int> MTRefference;

  auto start = high_resolution_clock::now();

  std::cin >> MTRefference.lineRefference;
  MTRefference.columnRefference = MTRefference.lineRefference;

  __initializeProcessor__.generateMatrix (MTRefference);
  io.outputMatrix (MTRefference);

  std::cout << '\n' << '\n';

  __initializeProcessor__.processSpecificMatrix(MTRefference);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "\n\n\nTime taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
