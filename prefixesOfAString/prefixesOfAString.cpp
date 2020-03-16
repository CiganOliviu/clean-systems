/*
  prefixes of a string
  Tasks:
    * print all the prefixes of a string
*/

#include <iostream>
#include <string.h>

class stringWorkFlow {

public:
  stringWorkFlow () {}

  void printAllPrefixesInString (char dataWorkFlow[]);

  virtual ~stringWorkFlow () {}
};

void stringWorkFlow::printAllPrefixesInString (char dataWorkFlow[]) {

  int jiterator = 0;

  while (jiterator < strlen(dataWorkFlow)) {

    for (size_t iterator = jiterator; iterator < strlen(dataWorkFlow); iterator++)
      std::cout << dataWorkFlow[iterator];

    std::cout << '\n';

    jiterator += 1;
  }
}

int main(int argc, char const *argv[]) {

  stringWorkFlow __workFlow__;
  char string[100];

  std::cin >> string;

  __workFlow__.printAllPrefixesInString (string);

  return 0;
}
