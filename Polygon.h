#ifndef POLYGON_H
#define POLYGON_H
#include "Point.h"
#include "Shape.h"
#include <string>

class Polygon : public Shape
{
public:
  Polygon(Point q[], int count) : m_a(q), m_c(count) {}
  Polygon() : m_a(0), m_c(0) {}
  //~Polygon() {delete[] m_a;} // Couldn't get this work. Deleting in main.cpp worked though.
  std::string getType();
  double getArea();
  double getCircumference();
  Point getPosition();
  bool isConvex();
  Polygon operator+(const Point &rhs); //Adds one(1) coordinate to the polygon
  Polygon operator+(const Polygon &rhs); //Adds two shapes(polygons)toghter
  void operator=(const Polygon& rhs);
  friend std::ostream& operator<<(std::ostream& os, const Polygon& rhs);

private:
  Point* m_a = nullptr;
  int m_c = 0;
};

#endif // POLYGON_H