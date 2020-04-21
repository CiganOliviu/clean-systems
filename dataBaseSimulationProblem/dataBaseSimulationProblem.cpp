#include "databaseSimulationProblemDef.hpp"

const char * systemException::what () const throw () {

  return processMessage.c_str();
}

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

  auto start = high_resolution_clock::now();

  operations.readDataFromDataBaseTable ((char*)"dataBase.database", students);
  operations.putsDataFromDataBaseTable (students);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "\n\n\nTime taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
