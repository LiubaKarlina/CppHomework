#include <stdio.h>
#include <cmath>

#include "rectangle.h"

Rectangle::Rectangle(int id, int x, int y, int width, int height): Figure(id, x, y), width(width), height(height)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::print() const
{
  printf("Rectangle %d: x = %d y = %d width = %d height = %d\n", id, x, y, width, height);
}

bool Rectangle::is_inside(int x, int y) const
{
  if (std::abs(this->x - x) * 2 <= width)
    if (std::abs(this->y - y) * 2 <= height)
      return true;

  return false;
}

void Rectangle::zoom(int factor)
{
  width *= factor;
  height *= factor;
}
