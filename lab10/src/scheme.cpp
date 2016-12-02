#include <stdio.h>

#include "scheme.h"

Scheme::Scheme(int capacity): capacity(capacity)
{
  size = 0;
  figures_ = new Figure *[capacity];
}
 
Scheme::~Scheme()
{
  for (int i = 0; i < size; ++i)
    delete figures_[i];
 
 delete[] figures_; 
}

void Scheme::push_back_figure(Figure* fg)
{
  if (size < capacity)
    figures_[size++] = fg;
}

void Scheme::remove_figure(int id) // элементы смещаются влево
{
  int i;
  for (i = 0; i < size; ++i)
    if (figures_[i]->GetId() == id) {
      delete figures_[i];
      while(i < size)
      {
        figures_[i] = figures_[i+1];
        i++;
      }
      size--; 
      break;
    }
}

void Scheme::print_all_figures()
{
  for (int i = 0; i < size; ++i)
    figures_[i]->print();
}

void Scheme::zoom_figure(int id, int factor)
{
  for (int i = 0; i < size; ++i)
    if (figures_[i]->GetId() == id) {
      figures_[i]->zoom(factor);
      break;
    }
}

Figure* Scheme::is_inside_figure(int x, int y) 
{
  for (int i = 0; i < size; ++i)
    if (figures_[i]->is_inside(x, y))
      return figures_[i];
  
  return 0;
}

void Scheme::move(int id, int new_x, int new_y)
{
  for (int i = 0; i < size; ++i)
    if (figures_[i]->GetId() == id) {
      figures_[i]->move(new_x, new_y);
      break;
    }
}
