#include <fstream>
#include <iostream>

#ifndef STD_LENGTH
#define STD_LENGTH 1000
#endif

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

class minMaxWorkFlow {
private:
  validationRules __validations__;

public:
  minMaxWorkFlow () {}

  template <class Type> void readOneDimensionalArray (char * fileName, oneDimensionalArrayType<Type> ODARefference);
  template <class Type> void outputOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference);
  template <class Type> Type maximOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference);
  template <class Type> Type minimOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference);
  template <class Type> void interchangeValues (Type * parameterOne, Type * parameterTwo);
  template <class Type> void interchangeMaxMin (oneDimensionalArrayType<Type> ODARefference);

  virtual ~minMaxWorkFlow () {}
};

template <class Type> void minMaxWorkFlow::readOneDimensionalArray (char * fileName, oneDimensionalArrayType<Type> ODARefference) {

  std::ifstream dataStream(fileName, std::ios::in);

  Type data;

  if (dataStream.is_open()) {

    while (dataStream >> data) {

      ODARefference.oneDimensionalArray[ODARefference.length] = data;
      ODARefference.length += 1;
    }

    if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to handle length as zero");
    if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to handle negative length");

    dataStream.close();
  }

  else throw systemException ("Unable to open file");
}

template <class Type> void minMaxWorkFlow::outputOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference) {

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to handle length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to handle negative length");
  else
    for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++)
      std::cout << ODARefference.oneDimensionalArray[iterator] << " ";
}

template <class Type> Type minMaxWorkFlow::maximOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference) {

  int maxim = ODARefference.oneDimensionalArray[0];

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to handle length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to handle negative length");
  else
    for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++)
      if (maxim < ODARefference.oneDimensionalArray[iterator])
        maxim = ODARefference.oneDimensionalArray[iterator];

  return maxim;
}

template <class Type> Type minMaxWorkFlow::minimOneDimensionalArray (oneDimensionalArrayType<Type> ODARefference) {

  int minim = ODARefference.oneDimensionalArray[0];

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to handle length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to handle negative length");
  else
    for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++)
      if (minim > ODARefference.oneDimensionalArray[iterator])
        minim = ODARefference.oneDimensionalArray[iterator];

  return minim;
}

template <class Type> void minMaxWorkFlow::interchangeValues (Type * parameterOne, Type * parameterTwo) {

  *parameterOne = *parameterOne + *parameterTwo;
  *parameterTwo = *parameterOne - *parameterTwo;
  *parameterOne = *parameterOne - *parameterTwo;
}

template <class Type> void minMaxWorkFlow::interchangeMaxMin (oneDimensionalArrayType<Type> ODARefference) {

  int maxim = maximOneDimensionalArray (ODARefference);
  int minim = minimOneDimensionalArray (ODARefference);
  int posMax, posMin;

  if (__validations__.isZero(ODARefference.length)) throw systemException ("Unable to handle length as zero");
  if (__validations__.isNegative(ODARefference.length)) throw systemException ("Unable to handle negative length");
  else
    for (size_t iterator = ODARefference.startPoint; iterator < ODARefference.length + ODARefference.endPoint; iterator++) {
      if (maxim == ODARefference.oneDimensionalArray[iterator]) posMax = iterator;
      if (minim == ODARefference.oneDimensionalArray[iterator]) posMin = iterator;
    }

  interchangeValues(&ODARefference.oneDimensionalArray[posMax], &ODARefference.oneDimensionalArray[posMin]);
}

int main(int argc, char const *argv[]) {

  minMaxWorkFlow minMaxRefference;
  oneDimensionalArrayType <int> ODARefference;

  minMaxRefference.readOneDimensionalArray ((char*)"ODA.data", ODARefference);
  minMaxRefference.outputOneDimensionalArray (ODARefference);
  std::cout << '\n';
  std::cout << minMaxRefference.minimOneDimensionalArray (ODARefference);
  std::cout << '\n';
  std::cout << minMaxRefference.maximOneDimensionalArray (ODARefference);
  minMaxRefference.interchangeMaxMin (ODARefference);
  std::cout << '\n';
  minMaxRefference.outputOneDimensionalArray (ODARefference);

  return 0;
}
