#include "graphIntroProblemDef.hpp"

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
