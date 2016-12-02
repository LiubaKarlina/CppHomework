#include <stdio.h>
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
  if (this->x <= x && this->x + width >= x)
    if (this->y <= y && this->y + height >= y)
      return true;

  return false;
}

void Rectangle::zoom(int factor)
{
  width *= factor;
  height *= factor;
}
