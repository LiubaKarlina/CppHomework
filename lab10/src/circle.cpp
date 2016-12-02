#include <string.h>
#include <stdio.h>

#include "circle.h"

Circle::Circle(int id, int x, int y, int radius, const char* label): Figure(id, x, y), rad(radius)
{
  Name = new char[strlen(label) + 1];
  strcpy(Name, label);
}

Circle::~Circle()
{
  delete[] Name;
}

void Circle::print() const
{
  printf("Circle %d: x = %d y = %d radius = %d ", id, x, y, rad);
  printf("label = %s\n", Name);
}

bool Circle::is_inside(int x, int y) const
{
  x = this->x - x;
  y = this->y - y;
  if (x * x + y * y <= rad)
    return true;
  return false;
}

void Circle::zoom(int factor)
{
  rad *= factor;
}
