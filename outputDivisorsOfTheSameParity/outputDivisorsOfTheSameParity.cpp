#include "outputDivisorsOfTheSameParityDef.hpp"

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

bool paritySupport::isOdd (int number) {

	if (__validations__.isNegative (number)) throw systemException ("Unable to process negative data");
	if (__validations__.isZero (number) ) return false;
	
	if (number % 2 == 1) return true;

	return false;
}

bool paritySupport::isEven (int number) {

	if (__validations__.isNegative (number)) throw systemException ("Unable to process negative data");
	if (__validations__.isZero (number) ) return false;

	if (number % 2 == 0) return true;

	return false;
}

int numbersProcessor::returnNumberOfOddDivisors (int number) {

	int result = 0;

	if (__validations__.isNegative (number)) return result;
	if (__validations__.isZero (number) ) return result;

	for (int iterator = 2; iterator <= number / 2; iterator ++)
		if (number % iterator == 0)
			if (__support__.isOdd(iterator))
				result += 1;	

	return result;
}

int numbersProcessor::returnNumberOfEvenDivisors (int number) {
	
	int result = 0;

	if (__validations__.isNegative (number)) return result;
	if (__validations__.isZero (number) ) return result;

	for (int iterator = 1; iterator <= number; iterator ++)
		if (number % iterator == 0)
			if (__support__.isEven(iterator))
				result += 1;	

	return result;
}

int numbersProcessor::returnNumberOfDivisorsOfTheSameParity (int number) {

	if (__validations__.isNegative (number)) return 0;
	if (__validations__.isZero (number) ) return 0;

	if (__support__.isOdd(number))
		return returnNumberOfOddDivisors(number);
	
	return returnNumberOfEvenDivisors(number);
}

int main (int argc, char const * argv[]) {

	numbersProcessor __processor__;

	int number;

	std::cin >> number;

	std::cout << __processor__.returnNumberOfDivisorsOfTheSameParity (number);

	return 0;
}