/*
  database simulation problem
  Tasks:
    * simulate a database with a table students
    * insert data through a file
    * select all data from it
*/

#include <fstream>
#include <iostream>
#include <string>

#ifndef STD_LENGTH
#define STD_LENGTH 100
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

class dataBaseTable {
private:
  unsigned int standardIntegerNumbersTypeInitialisation = 0;
  unsigned int standardFloatNumbersTypeInitialisation = 0.0;
  std::string standardVarCharInitialisation = "NULL";

public:
  dataBaseTable () {}

  unsigned int ID = standardIntegerNumbersTypeInitialisation;
  std::string firstName = standardVarCharInitialisation;
  std::string lastName = standardVarCharInitialisation;
  std::string profile = standardVarCharInitialisation;
  oneDimensionalArrayType<float> marks;
  float average = standardFloatNumbersTypeInitialisation;
  std::string situation = standardVarCharInitialisation;

  virtual ~dataBaseTable () {}
};

class operationsOnDataBaseTable {
private:
  float getAverageMarksForFieldAverage (oneDimensionalArrayType<float> ODAObject);
  void outputOneDimensionalArray (oneDimensionalArrayType<float> ODAObject);
  void setSituationBasedOnMark (dataBaseTable & dataBaseObject);

public:
  operationsOnDataBaseTable () {}

  void readDataFromDataBaseTable (char * fileName, dataBaseTable & dataBaseObject);
  void putsDataFromDataBaseTable (dataBaseTable dataBaseObject);

  virtual ~operationsOnDataBaseTable () {}
};

float operationsOnDataBaseTable::getAverageMarksForFieldAverage (oneDimensionalArrayType<float> ODAObject) {

  float sum = 0;

  for (size_t iterator = ODAObject.startPoint; iterator < ODAObject.length + ODAObject.endPoint; iterator++)
    sum += ODAObject.oneDimensionalArray[iterator];

  return sum / 3;
}

void operationsOnDataBaseTable::outputOneDimensionalArray (oneDimensionalArrayType<float> ODAObject) {

  for (size_t iterator = ODAObject.startPoint; iterator < ODAObject.length + ODAObject.endPoint; iterator++)
    std::cout << ODAObject.oneDimensionalArray[iterator] << " ";
  std::cout << '\n';
}

void operationsOnDataBaseTable::setSituationBasedOnMark (dataBaseTable & dataBaseObject) {

  if (dataBaseObject.average >= 6.00) dataBaseObject.situation = "Passed";
  else
    dataBaseObject.situation = "Failed";
}

void operationsOnDataBaseTable::readDataFromDataBaseTable (char * fileName, dataBaseTable & dataBaseObject) {

  std::ifstream dataStream (fileName, std::ios::in);

  if (dataStream.is_open()) {

    dataBaseObject.marks.length = 3;

    dataBaseObject.ID += 1;

    for (size_t iterator = dataBaseObject.marks.startPoint; iterator < dataBaseObject.marks.length + dataBaseObject.marks.endPoint; iterator++)
      dataStream >> dataBaseObject.marks.oneDimensionalArray[iterator];

    dataStream >> dataBaseObject.firstName;
    dataStream >> dataBaseObject.lastName;
    dataStream >> dataBaseObject.profile;
    dataBaseObject.average = getAverageMarksForFieldAverage (dataBaseObject.marks);
    setSituationBasedOnMark (dataBaseObject);

    dataStream.close();
  }
  else
    throw systemException ("Unable to open file");
}

void operationsOnDataBaseTable::putsDataFromDataBaseTable (dataBaseTable dataBaseObject) {

  std::cout << dataBaseObject.ID << '\n';
  std::cout << dataBaseObject.firstName << '\n';
  std::cout << dataBaseObject.lastName << '\n';
  std::cout << dataBaseObject.profile << '\n';
  outputOneDimensionalArray (dataBaseObject.marks);
  std::cout << dataBaseObject.average << '\n';
  std::cout << dataBaseObject.situation;
}

int main(int argc, char const *argv[]) {

  dataBaseTable students;
  operationsOnDataBaseTable operations;

  operations.readDataFromDataBaseTable ((char*)"dataBase.database", students);
  operations.putsDataFromDataBaseTable (students);

  return 0;
}
