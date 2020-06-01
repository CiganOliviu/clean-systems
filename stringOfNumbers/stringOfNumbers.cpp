#include "stringOfNumbersDef.hpp"

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

template <class Type> bool validationRules::isZeroOrNegative (Type parameter) {

  if (parameter <= 0) return true;

  return false;
}

int stringOfNumbers::generateSpecificTermRecursively (int index) {

  if (__validations__.isZeroOrNegative(index)) throw systemException ("Unable to process negative or zero index. It should start at 1");

  if (index == 1 || index == 2) return 1;

  return 3 * generateSpecificTermRecursively (index - 1) - generateSpecificTermRecursively (index - 2);
}

int stringOfNumbers::foundIndexForSpecificTerm (int term) {

  if (__validations__.isZeroOrNegative(term)) throw systemException ("Unable to process negative or zero index. It should start at 1");

  int result = 1;

  while (generateSpecificTermRecursively(result) != term)
    result += 1;

  return result;
}

void inputOutputSystem::outputStringOfNumbers (int limit) {

    if (__validations__.isZeroOrNegative(limit)) throw systemException ("Unable to process negative or zero index. It should start at 1");

    int iterator = __stringObject__.foundIndexForSpecificTerm (limit);

    while (iterator >= 1) {

      std::cout << __stringObject__.generateSpecificTermRecursively (iterator) << " ";

      iterator -= 1;
    }
}

int main (int argc, char const * argv[]) {

  inputOutputSystem ioSystem;

  int limit;

  auto start = high_resolution_clock::now();

  std::cin >> limit;

  ioSystem.outputStringOfNumbers (limit);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "\n\n\nTime taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
