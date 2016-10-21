#include "my_vector.h"

void Swap(int &a, int &b)
{
  int tmp = a;
  a = b;
  b = tmp;
}

MyVector::MyVector()
{
  _data = new int[2];
  _sz = 0;
  _cp = 2;
}

MyVector::MyVector(std::size_t init_capacity)
{
  _data = new int[init_capacity];
  _sz = 0;
  _cp = init_capacity;
}

MyVector::~MyVector()
{
  delete[]_data;
}

void MyVector::set(std::size_t index, int value)
{
  if (index < _sz)
    _data[index] = value;
}

int MyVector::get(std::size_t index)
{
  if (index < _sz)
    return _data[index];
  return -1;
}

std::size_t MyVector::size(){
  return _sz;
}

std::size_t MyVector::capacity(){
  return _cp;
}

void MyVector::reserve(std::size_t new_capacity)
{
  int *b = new int[new_capacity];
  
  for (ui i = 0;i < _sz;i++)
    b[i] = _data[i];

  delete[] _data;
  _data = b;
  _cp = new_capacity; 
}

void MyVector::resize(std::size_t new_size)
{
  int *b = new int[new_size];
  for (ui i = 0;i < _sz;i++)
    b[i] = _data[i];
  for (ui i = _sz;i < _cp;i++)
    b[i] = 0;
  delete[] _data;
  _data = b;
  _sz = new_size;
  _cp = new_size;   
}
  
void MyVector::push_back(int value)
{ 
  if (_sz == _cp)
    reserve(_cp * 2);
  _data[_sz++] = value;
}

void MyVector::insert(std::size_t index, int value)
{
  if (index < _sz)
  {
    if (_sz == _cp)
      reserve(_cp * 2);
    _data[_sz] = value;
    for (ui i = _sz;i > index;i--)
      Swap(_data[i], _data[i - 1]);
    _sz++;  
  }
}

void MyVector::erase(std::size_t index)
{
  if (index < _sz)
  {
    for (ui i = index;i < _sz - 1;i++)
      Swap(_data[i], _data[i + 1]);
    _sz--;  
  }
}
