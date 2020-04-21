/*
  database simulation problem
  Tasks:
    * simulate a database with a table students
    * insert data through a file
    * select all data from it
*/

#include <chrono>
#include <fstream>
#include <iostream>
#include <string>

#ifndef STD_LENGTH
#define STD_LENGTH 100
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
