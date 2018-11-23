#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Point.h"
#include "Shape.h"
#include "Functions.h"

class Triangle : public Shape
{

public:
  Triangle(Point q, Point w, Point e) : m_p1(q), m_p2(w), m_p3(e) {}
  Triangle() : m_p1(0, 0), m_p2(0, 0), m_p3(0, 0) {}
  double getArea();
  double getCircumreference();
  Point position();

private:
  Point m_p1;
  Point m_p2;
  Point m_p3;
};

#endif // TRIANGLE_H