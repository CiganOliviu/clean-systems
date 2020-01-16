/*
  one dimensional array data process problem
  Tasks:
    * read one dimensional array from a file
    * print one dimensional array with the new values
    * save the prime values from the array and print them
    * save the non prime values from the array and print them
    * sort the prime values and print them
    * sort the non prime values and print them
*/

#include <chrono>
#include <fstream>
#include <iostream>

#ifndef STD_LENGTH
#define STD_LENGTH 100000
#endif

using namespace std::chrono;

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

class processData {
private:

public:
  processData () {}

  template <class Type> inline void interchangeValues (Type * parameterOne, Type * parameterTwo);
  template <class Type> bool isPrime (Type parameter);
  template <class Type> void readOneDimensionalArray (char * fileName, oneDimensionalArrayType<Type> ODARefference);
  template <class Type> void outputOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference);
  template <class Type> oneDimensionalArrayType<Type> getPrimeValueOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference);
  template <class Type> oneDimensionalArrayType<Type> getNonPrimeValueOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference);
  template <class Type> void bubbleSort (oneDimensionalArrayType<Type> ODARefference);

  virtual ~processData () {}
};

template <class Type> void processData::interchangeValues (Type * parameterOne, Type * parameterTwo) {

  *parameterOne = *parameterOne + *parameterTwo;
  *parameterTwo = *parameterOne - *parameterTwo;
  *parameterOne = *parameterOne - *parameterTwo;
}

template <class Type> bool processData::isPrime (Type parameter) {

  if (parameter <= 0) return false;

  if (parameter == 2) return true;

  for (size_t iterator = 2; iterator <= parameter / 2; iterator++)
    if (parameter % iterator == 0) return false;

  return true;
}

template <class Type> void processData::readOneDimensionalArray (char * fileName, oneDimensionalArrayType<Type> ODARefference) {

    std::ifstream dataStream(fileName, std::ios::in);
    Type data;

    if (dataStream.is_open()) {

      while (dataStream >> data) {
          ODARefference.oneDimensionalArray[ODARefference.length] = data;
          ODARefference.length += 1;
      }

      if (ODARefference.length == 0) systemException ("Unable to work with length as zero");
      if (ODARefference.length < 0) systemException ("Unable to work with negative length");

      dataStream.close();
    }
    else
      systemException ("Unable to open file");
}

template <class Type> void processData::outputOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference) {

  if (ODARefference.length == 0) systemException ("Unable to work with length as zero");
  if (ODARefference.length < 0) systemException ("Unable to work with negative length");

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++)
    std::cout << ODARefference.oneDimensionalArray[iterator] << " ";
  std::cout << '\n' << '\n' << '\n';
}

template <class Type> oneDimensionalArrayType<Type> processData::getPrimeValueOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference) {

  if (ODARefference.length == 0) systemException ("Unable to work with length as zero");
  if (ODARefference.length < 0) systemException ("Unable to work with negative length");

  oneDimensionalArrayType<Type> primeValuesOneDimensionalArray;

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++)
    if (isPrime(ODARefference.oneDimensionalArray[iterator])) {
      primeValuesOneDimensionalArray.oneDimensionalArray[primeValuesOneDimensionalArray.length] = ODARefference.oneDimensionalArray[iterator];
      primeValuesOneDimensionalArray.length += 1;
    }

  return primeValuesOneDimensionalArray;
}

template <class Type> oneDimensionalArrayType<Type> processData::getNonPrimeValueOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference) {

  if (ODARefference.length == 0) systemException ("Unable to work with length as zero");
  if (ODARefference.length < 0) systemException ("Unable to work with negative length");

  oneDimensionalArrayType<Type> nonePrimeValuesOneDimensionalArray;

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++)
    if (!isPrime(ODARefference.oneDimensionalArray[iterator])) {
      nonePrimeValuesOneDimensionalArray.oneDimensionalArray[nonePrimeValuesOneDimensionalArray.length] = ODARefference.oneDimensionalArray[iterator];
      nonePrimeValuesOneDimensionalArray.length += 1;
    }

  return nonePrimeValuesOneDimensionalArray;
}

template <class Type> void processData::bubbleSort (oneDimensionalArrayType<Type> ODARefference) {

  if (ODARefference.length == 0) systemException ("Unable to work with length as zero");
  if (ODARefference.length < 0) systemException ("Unable to work with negative length");

  for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint - 1; iterator++)
      for (size_t jiterator = ODARefference.startPoint; jiterator < ODARefference.length + ODARefference.endPoint - iterator - 1; jiterator++)
        if (ODARefference.oneDimensionalArray[jiterator] > ODARefference.oneDimensionalArray[jiterator + 1])
          interchangeValues (&ODARefference.oneDimensionalArray[jiterator], &ODARefference.oneDimensionalArray[jiterator + 1]);
}

class objectsWorkFlow {

public:
  objectsWorkFlow () {}

  template <class Type> void portData (oneDimensionalArrayType<Type> ODARefferenceOne, oneDimensionalArrayType<Type> ODARefferenceTwo);

  virtual ~objectsWorkFlow () {}
};

template <class Type> void objectsWorkFlow::portData (oneDimensionalArrayType<Type> ODARefferenceOne, oneDimensionalArrayType<Type> ODARefferenceTwo) {

  ODARefferenceOne.length = ODARefferenceTwo.length;
  ODARefferenceOne.startPoint = ODARefferenceTwo.startPoint;
  ODARefferenceOne.endPoint = ODARefferenceTwo.endPoint;

  for (size_t iterator = ODARefferenceOne.startPoint; iterator < ODARefferenceOne.length + ODARefferenceOne.endPoint; iterator++)
    ODARefferenceOne.oneDimensionalArray[iterator] = ODARefferenceTwo.oneDimensionalArray[iterator];
}

int main(int argc, char const *argv[]) {

  processData processDataObject;
  objectsWorkFlow objectsRefference;
  oneDimensionalArrayType<int> ODAObject;
  oneDimensionalArrayType<int> primeValuesODA;
  oneDimensionalArrayType<int> nonePrimeValuesODA;

  auto start = high_resolution_clock::now();

  processDataObject.readOneDimensionalArray<int> ((char*)"ODA.data", ODAObject);
  processDataObject.outputOneDimensionalArray<int> (ODAObject);

  objectsRefference.portData<int> (primeValuesODA, processDataObject.getPrimeValueOneDimensionalArray<int> (ODAObject));
  processDataObject.outputOneDimensionalArray<int> (primeValuesODA);

  objectsRefference.portData<int> (nonePrimeValuesODA, processDataObject.getNonPrimeValueOneDimensionalArray<int> (ODAObject));
  processDataObject.outputOneDimensionalArray<int> (nonePrimeValuesODA);

  processDataObject.bubbleSort (primeValuesODA);
  processDataObject.outputOneDimensionalArray (primeValuesODA);

  processDataObject.bubbleSort (nonePrimeValuesODA);
  processDataObject.outputOneDimensionalArray (nonePrimeValuesODA);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
