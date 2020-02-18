/*
  graph intro problem
  Task:
    * read graph by edges list
    * output the adjacency matrix
    * output the valency of vertices
    * output the neightbours list
*/

#include <chrono>
#include <fstream>
#include <iostream>

#ifndef STD_LENGTH
#define STD_LENGTH 1000
#endif

#ifndef MATRIX_STD_LENGTH
#define MATRIX_STD_LENGTH 100
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

template <class Type> class matrixType {
private:
  int standardSize = 0;

public:
  matrixType () {}

  int line = standardSize;
  int & lineRefference = line;
  int column = standardSize;
  int & columnRefference = column;

  int startLinePoint = standardSize;
  int endLinePoint = standardSize;
  int startColumnPoint = standardSize;
  int endColumnPoint = standardSize;

  Type matrix[MATRIX_STD_LENGTH][MATRIX_STD_LENGTH];

  virtual ~matrixType () {}
};

template <class Type> class graphType {
private:
  int standardSize = 0;

public:
  graphType () {
    adjacencyMatrix.line = vertices;
    adjacencyMatrix.column = adjacencyMatrix.line;
    adjacencyMatrix.startLinePoint = adjacencyMatrix.startColumnPoint;
    adjacencyMatrix.endLinePoint = adjacencyMatrix.endColumnPoint;
  }

  int vertices = standardSize;
  int & verticesRefference = vertices;
  int edges = standardSize;
  int & edgesRefference = edges;

  matrixType<Type> adjacencyMatrix;
  oneDimensionalArrayType<Type> verticesValency;

  virtual ~graphType () {}
};

class graphsWorkFlow {
private:
  validationRules __validations__;

public:
  graphsWorkFlow () {}

  void readEdgesList (graphType<int> & graphObject);
  void outputAdjacencyMatrix (graphType<int> graphObject);
  void outputGraphVerticesValency (graphType<int> graphObject);
  void outputGraphNeighboursList (graphType<int> graphObject);

  virtual ~graphsWorkFlow () {}
};

void graphsWorkFlow::readEdgesList (graphType<int> & graphObject) {

  int nodeOne, nodeTwo;

  std::cin >> graphObject.vertices >> graphObject.edges;

  graphObject.adjacencyMatrix.lineRefference = graphObject.vertices;
  graphObject.adjacencyMatrix.columnRefference = graphObject.vertices;

  for (size_t iterator = 1; iterator <= graphObject.edges; iterator++) {

    std::cin >> nodeOne >> nodeTwo;

    graphObject.adjacencyMatrix.matrix[nodeOne][nodeTwo] = 1;
    graphObject.adjacencyMatrix.matrix[nodeTwo][nodeOne] = 1;
  }
}

void graphsWorkFlow::outputAdjacencyMatrix (graphType<int> graphObject) {

  if (__validations__.isZero(graphObject.adjacencyMatrix.lineRefference) || __validations__.isZero(graphObject.adjacencyMatrix.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__validations__.isNegative(graphObject.adjacencyMatrix.lineRefference) || __validations__.isNegative(graphObject.adjacencyMatrix.columnRefference)) throw systemException ("Unable to process with negative line or column");

  for (size_t iterator = graphObject.adjacencyMatrix.startLinePoint; iterator < graphObject.adjacencyMatrix.lineRefference + graphObject.adjacencyMatrix.endLinePoint; iterator++) {
    for (size_t jiterator = graphObject.adjacencyMatrix.startColumnPoint; jiterator < graphObject.adjacencyMatrix.columnRefference + graphObject.adjacencyMatrix.endColumnPoint; jiterator++)
      std::cout << graphObject.adjacencyMatrix.matrix[iterator][jiterator] << " ";
    std::cout << '\n';
  }
}

void graphsWorkFlow::outputGraphVerticesValency (graphType<int> graphObject) {

  if (__validations__.isZero(graphObject.adjacencyMatrix.lineRefference) || __validations__.isZero(graphObject.adjacencyMatrix.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__validations__.isNegative(graphObject.adjacencyMatrix.lineRefference) || __validations__.isNegative(graphObject.adjacencyMatrix.columnRefference)) throw systemException ("Unable to process with negative line or column");

  int valency = 0;

  for (size_t iterator = graphObject.adjacencyMatrix.startLinePoint; iterator < graphObject.adjacencyMatrix.lineRefference + graphObject.adjacencyMatrix.endLinePoint; iterator++) {
    for (size_t jiterator = graphObject.adjacencyMatrix.startColumnPoint; jiterator < graphObject.adjacencyMatrix.columnRefference + graphObject.adjacencyMatrix.endColumnPoint; jiterator++)
      if (graphObject.adjacencyMatrix.matrix[iterator][jiterator] == 1)
        valency += 1;

    std::cout << valency << " ";

    valency = 0;
  }
}

void graphsWorkFlow::outputGraphNeighboursList (graphType<int> graphObject) {

  if (__validations__.isZero(graphObject.adjacencyMatrix.lineRefference) || __validations__.isZero(graphObject.adjacencyMatrix.columnRefference)) throw systemException ("Unable to process with line or column as zero");
  if (__validations__.isNegative(graphObject.adjacencyMatrix.lineRefference) || __validations__.isNegative(graphObject.adjacencyMatrix.columnRefference)) throw systemException ("Unable to process with negative line or column");

  for (size_t iterator = graphObject.adjacencyMatrix.startLinePoint; iterator < graphObject.adjacencyMatrix.lineRefference + graphObject.adjacencyMatrix.endLinePoint; iterator++) {
    for (size_t jiterator = graphObject.adjacencyMatrix.startColumnPoint; jiterator < graphObject.adjacencyMatrix.columnRefference + graphObject.adjacencyMatrix.endColumnPoint; jiterator++)
      if (graphObject.adjacencyMatrix.matrix[iterator][jiterator] == 1)
        std::cout << jiterator << " ";
    std::cout << '\n';
  }
}

int main(int argc, char const *argv[]) {

  graphsWorkFlow GWorkFlow;
  graphType<int> graphObject;

  graphObject.adjacencyMatrix.startLinePoint = 1;
  graphObject.adjacencyMatrix.endLinePoint = 1;
  graphObject.adjacencyMatrix.startColumnPoint = 1;
  graphObject.adjacencyMatrix.endColumnPoint = 1;

  auto start = high_resolution_clock::now();

  GWorkFlow.readEdgesList (graphObject);
  GWorkFlow.outputAdjacencyMatrix (graphObject);

  std::cout << '\n';

  GWorkFlow.outputGraphVerticesValency (graphObject);

  std::cout << '\n' << '\n';

  GWorkFlow.outputGraphNeighboursList (graphObject);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<seconds>(stop - start);

  std::cout << "\n\n\nTime taken by tasks: " << duration.count() << " seconds" << '\n';

  return 0;
}
