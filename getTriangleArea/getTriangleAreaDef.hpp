/*
  numbers process
  Tasks:
    * calculate the triangle area
*/

#include <chrono>
#include <fstream>
#include <iostream>
#include <math.h>

#ifndef STD_LENGTH
#define STD_LENGTH 1000
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

class Point {

public:
  Point () {}  

  float Xs;
  float Ys;

  virtual ~Point() {}
};

class Triangle {

public:
  Triangle () {}

  Point pointA;
  Point pointB;
  Point pointC;

  virtual ~Triangle() {}
};

class inputOutputSystem {
public:
  inputOutputSystem () {}

  void readPoint (Point & point);
  void outputPoint (Point point);

  virtual ~inputOutputSystem () {}
};

class triangleWorkFlow {
private:
  validationRules __validations__;

  float getDistanceBetweenTwoPoints (Point pointA, Point pointB);  
  float getSemiPerimeterOfTriangle (float distanceOne, float distanceTwo, float distanceThree);

public:
  triangleWorkFlow () {}

  float getTriangleArea (Triangle shape);
  float getTrianglePerimeter (Triangle shape);

  virtual ~triangleWorkFlow () {}
};