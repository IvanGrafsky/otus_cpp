#include <iostream>
#include "figure.hpp"

void Point::About() {
  std::cout << "This is point" << std::endl;
}

void Line::About() {
  std::cout << "This is Line" << std::endl;
}

void Rectangle::About() {
  std::cout << "This is Rectangle" << std::endl;
}

void Circle::About() {
  std::cout << "This is Circle" << std::endl;
}
