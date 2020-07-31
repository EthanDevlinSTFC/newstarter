#include "Shape.h"

// Shape constructor
Shape::Shape(std::string stype, int sides) {
  m_type = stype;
  m_sides = sides;
}

Shape::~Shape() {};

/** Return a string containing information for a given shape
 *  @return shape string
 */ 
std::string Shape::shapeToString() {
  std::string periString = std::to_string(m_perimeter);
  std::string areaString = std::to_string(m_area);
  std::string sideString = std::to_string(m_sides);

  std::string retnString = sideString + " sided " + m_type + " with p=" + periString + ", a=" + areaString;
  return retnString;
}

//Mutator methods
void Shape::setPerimeter(double perimeter) {
  m_perimeter = perimeter;
}

void Shape::setArea(double area) {
  m_area = area;
}

void Shape::setType(std::string type) {
  m_type = type;
}

void Shape::setSides(int sides) {
  m_sides = sides;
}

//Accessor methods
double Shape::getPerimeter() {
  return m_perimeter;
}

double Shape::getArea() {
  return m_area;
}

std::string Shape::getType(){
  return m_type;
}

int Shape::getSides() {
  return m_sides;
}  