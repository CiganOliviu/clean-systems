#include "decodeWordDef.hpp"

const char * systemException::what () const throw () {

  return processMessage.c_str();
}

bool validationRules::isNegative (char parameter[]) {

  if (strlen(parameter) < 0) return true;

  return false;
}

bool validationRules::isZero (char parameter[]) {

  if (strlen(parameter) == 0) return true;

  return false;
}

template <class Type> void portData::portOneDimensionalArray (oneDimensionalArrayType<Type> ODAObjectOne, oneDimensionalArrayType<Type> ODAObjectTwo) {

  ODAObjectOne.length = ODAObjectTwo.length;
  ODAObjectOne.startPoint = ODAObjectTwo.startPoint;
  ODAObjectOne.endPoint = ODAObjectTwo.endPoint;

  for (size_t iterator = ODAObjectOne.startPoint; iterator < ODAObjectOne.length + ODAObjectOne.endPoint; iterator++)
    ODAObjectOne.oneDimensionalArray[iterator] = ODAObjectTwo.oneDimensionalArray[iterator];
}

void inputOutputSystem::readOneDimensionalArray (oneDimensionalArrayType<char> dataWorkFlow) {

  if (__validations__.isZero(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process negative length");

  std::cin.getline (dataWorkFlow.oneDimensionalArray, dataWorkFlow.length);

}

void inputOutputSystem::outputOneDimensionalArray (oneDimensionalArrayType<char> dataWorkFlow) {

  if (__validations__.isZero(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(dataWorkFlow.oneDimensionalArray)) throw systemException ("Unable to process negative length");

  std::cout << dataWorkFlow.oneDimensionalArray << '\n';
}

int stringWorkFlow::convertCharToInt (char character) {

  int result;

  result = character - '\0';

  return result;
}

bool stringWorkFlow::isOdd (int number) {

  if (number % 2 == 1) return true;

  return false;
}

bool stringWorkFlow::isEven (int number) {

  if (number % 2 == 0) return true;

  return false;
}

oneDimensionalArrayType<char> stringWorkFlow::decodeWord (oneDimensionalArrayType<char> dataWorkFlowOne, oneDimensionalArrayType<char> dataWorkFlowTwo) {

  if (__validations__.isZero(dataWorkFlowOne.oneDimensionalArray)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(dataWorkFlowOne.oneDimensionalArray)) throw systemException ("Unable to process negative length");

  if (__validations__.isZero(dataWorkFlowTwo.oneDimensionalArray)) throw systemException ("Unable to process length as zero");
  if (__validations__.isNegative(dataWorkFlowTwo.oneDimensionalArray)) throw systemException ("Unable to process negative length");

  int contor = 0;
  oneDimensionalArrayType<char> result;
  
  result.length = 100;

  for (int iterator = strlen (dataWorkFlowTwo.oneDimensionalArray) - 1; iterator >= dataWorkFlowTwo.startPoint; iterator--)
    if (isEven (convertCharToInt (dataWorkFlowTwo.oneDimensionalArray[iterator]))) {
      result.oneDimensionalArray[contor] = dataWorkFlowOne.oneDimensionalArray[iterator];
      contor += 1;
    }

  for (int iterator = dataWorkFlowTwo.startPoint; iterator < strlen (dataWorkFlowTwo.oneDimensionalArray); iterator++)
    if (isOdd (convertCharToInt (dataWorkFlowTwo.oneDimensionalArray[iterator]))) {
      result.oneDimensionalArray[contor] = dataWorkFlowOne.oneDimensionalArray[iterator];
      contor += 1;
  }

  return result;
} 

int main (int argc, char const *argv[]) {

  oneDimensionalArrayType<char> string;
  oneDimensionalArrayType<char> code;
  oneDimensionalArrayType<char> result;

  inputOutputSystem IOSystem;
  portData __port__;
  stringWorkFlow workflow;

  string.length = 100;
  code.length = 100;
  result.length = 100;

  IOSystem.readOneDimensionalArray (string);
  IOSystem.readOneDimensionalArray (code);

  auto start = high_resolution_clock::now();

  __port__.portOneDimensionalArray (result, workflow.decodeWord (string, code));
  
  IOSystem.outputOneDimensionalArray (result);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "Time taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
