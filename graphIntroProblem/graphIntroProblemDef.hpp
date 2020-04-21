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

class validationRules {

public:
  validationRules () {}

  template <class Type> bool isNegative (Type parameter);
  template <class Type> bool isZero (Type parameter);

  virtual ~validationRules () {}
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
