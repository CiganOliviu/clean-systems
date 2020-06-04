#include "getTriangleAreaDef.hpp"

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

void inputOutputSystem::readPoint (Point & point) {

  std::cin >> point.Xs;
  std::cin >> point.Ys;
}

void inputOutputSystem::outputPoint (Point point) {

  std::cout << point.Xs << " " << point.Ys << '\n';
}

float triangleWorkFlow::getDistanceBetweenTwoPoints (Point pointA, Point pointB) {

  float distance;

  distance = sqrt(pow(pointA.Xs - pointB.Xs, 2) + pow(pointA.Ys - pointB.Ys, 2));

  return (float)distance;
}

float triangleWorkFlow::getSemiPerimeterOfTriangle (float distanceOne, float distanceTwo, float distanceThree) {

  float result;

  result = distanceOne + distanceTwo + distanceThree;

  result /= 2;

  return (float)result;
}

float triangleWorkFlow::getTriangleArea (Triangle shape) {

  float distanceOne = getDistanceBetweenTwoPoints(shape.pointA, shape.pointB);
  float distanceTwo = getDistanceBetweenTwoPoints(shape.pointA, shape.pointC);
  float distanceThree = getDistanceBetweenTwoPoints(shape.pointB, shape.pointC);

  float semiPerimeter;
  semiPerimeter = getSemiPerimeterOfTriangle(distanceOne, distanceTwo, distanceThree);

  float result;
  result = sqrt(semiPerimeter * (semiPerimeter - distanceOne) * (semiPerimeter - distanceTwo) * (semiPerimeter - distanceThree));

  return (float)result;
}

float triangleWorkFlow::getTrianglePerimeter (Triangle shape) {
  
  float distanceOne = getDistanceBetweenTwoPoints(shape.pointA, shape.pointB);
  float distanceTwo = getDistanceBetweenTwoPoints(shape.pointA, shape.pointC);
  float distanceThree = getDistanceBetweenTwoPoints(shape.pointB, shape.pointC);

  float result;
  result = distanceOne + distanceTwo + distanceThree;

  return (float)result;
}

int main (int argc, char const * argv[]) {

  inputOutputSystem ioSystem;
  triangleWorkFlow TriangleWF;

  Triangle shape;

  ioSystem.readPoint (shape.pointA);
  ioSystem.readPoint (shape.pointB);
  ioSystem.readPoint (shape.pointC);

  ioSystem.outputPoint (shape.pointA);
  ioSystem.outputPoint (shape.pointB);
  ioSystem.outputPoint (shape.pointC);

  std::cout << TriangleWF.getTriangleArea (shape) << '\n';
  std::cout << TriangleWF.getTrianglePerimeter (shape);

  return 0;
}