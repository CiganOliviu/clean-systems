/*
  ordered sequences
  Tasks:
    * read one dimensional array
    * print one dimensional array
    * get the ordered sequences from the array
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

class objectsWorkFlow {
private:
  validationRules __validations__;

public:
  objectsWorkFlow () {}

  template <class Type> void portData (oneDimensionalArrayType<Type> ODARefferenceOne, oneDimensionalArrayType<Type> ODARefferenceTwo);

  virtual ~objectsWorkFlow () {}
};

template <class Type> void objectsWorkFlow::portData (oneDimensionalArrayType<Type> ODARefferenceOne, oneDimensionalArrayType<Type> ODARefferenceTwo) {

  if (__validations__.isZero(ODARefferenceTwo.length)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(ODARefferenceTwo.length)) throw systemException ("Unable to process negative length");

  ODARefferenceOne.length = ODARefferenceTwo.length;
  ODARefferenceOne.startPoint = ODARefferenceTwo.startPoint;
  ODARefferenceOne.endPoint = ODARefferenceTwo.endPoint;

  for (size_t iterator = ODARefferenceOne.startPoint; iterator < ODARefferenceOne.length + ODARefferenceOne.endPoint; iterator++)
    ODARefferenceOne.oneDimensionalArray[iterator] = ODARefferenceTwo.oneDimensionalArray[iterator];
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

class orderedSequencesWorkFlow {
private:
  validationRules __validations__;

public:
 orderedSequencesWorkFlow () {}

 template <class Type> oneDimensionalArrayType<Type> getOrderedSequenceInOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference);

  virtual ~orderedSequencesWorkFlow () {}
};

template <class Type> oneDimensionalArrayType<Type> orderedSequencesWorkFlow::getOrderedSequenceInOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to process negative length");

  oneDimensionalArrayType<Type> orderedSequence;
  Type lastValue;

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint - 1; iterator++)
    if (ODARefference.oneDimensionalArray[iterator] < ODARefference.oneDimensionalArray[iterator + 1]) {
      orderedSequence.oneDimensionalArray[orderedSequence.length] = ODARefference.oneDimensionalArray[iterator];
      orderedSequence.length += 1;
      lastValue = ODARefference.oneDimensionalArray[iterator + 1];
    }

  orderedSequence.oneDimensionalArray[orderedSequence.length] = lastValue;
  orderedSequence.length += 1;

  return orderedSequence;
}

int main(int argc, char const *argv[]) {

  objectsWorkFlow objectsRefference;
  oneDimensionalArrayType<int> ODAObject;
  oneDimensionalArrayType<int> orderedSequence;
  inputOutputOperations io;
  orderedSequencesWorkFlow ODWorkFlow;

  auto start = high_resolution_clock::now();

  io.readOneDimensionalArray<int> ((char*)"ODA.data", ODAObject);
  io.outputOneDimensionalArray<int> (ODAObject);

  objectsRefference.portData<int> (orderedSequence, ODWorkFlow.getOrderedSequenceInOneDimensionalArray<int> (ODAObject));

  io.outputOneDimensionalArray<int> (orderedSequence);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
