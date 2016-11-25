#include <algorithm>

#include "matrix.h"

Matrix::Matrix(std::size_t r, std::size_t c) {
    int *buf = new int [r * c];
    _rows = r;
    _cols = c;
    _data = new int *[r];

    for (size_t i = 0;i < r;i++)
        _data[i] = buf + r * i;

    for (size_t i = 0;i < _rows;i++)
        for (size_t j = 0;j < _cols;j++)
            _data[i][j] = 0;

}

Matrix::Matrix(Matrix const &M) {
    _rows = M.get_rows();
    _cols = M.get_cols();
    int *buf = new int [_rows * _cols];
    _data = new int *[_rows];

    for (size_t i = 0;i < _rows;i++)
        _data[i] = buf + i *_cols;

    for (size_t i = 0;i < _rows;i++)
        for (size_t j = 0;j < _cols;j++)
            _data[i][j] = M._data[i][j];
}

void Matrix::del_data()
{
  delete []_data[0];
  delete []_data;
}

Matrix::~Matrix() {

  del_data();
}

Matrix& Matrix::swap(Matrix& m)
{
  std::swap(_rows, m._rows);
  std::swap(_cols, m._cols);

  std::swap(_data, m._data);

  return *this;
}

std::size_t Matrix::get_rows() const { return  _rows; }
std::size_t Matrix::get_cols() const { return  _cols; }

void Matrix::set(std::size_t i, std::size_t j, int val) {
  _data[i][j] = val;
}

int Matrix::get(std::size_t i, std::size_t j) {
    return _data[i][j];
}

void Matrix::print(FILE* f) {

    for (size_t i = 0;i < _rows;i++) {
        for (size_t j = 0; j < _cols; j++)
            fprintf(f, "%i ", _data[i][j]);
        fprintf(f, "\n");
    }

}

bool Matrix::operator==(const Matrix& m) const {

    for (size_t i = 0;i < _rows;i++)
        for (size_t j = 0;j < _cols;j++)
            if (_data[i][j] != m._data[i][j])
                return false;

    return true;
}

bool Matrix::operator!=(const Matrix& m) const {
    return !(*this==m);
}

Matrix& Matrix::operator+=(const Matrix& m) {
    for (size_t i = 0;i < _rows;i++)
        for (size_t j = 0;j < _cols;j++)
            _data[i][j] += m._data[i][j];

    return *this;
}

Matrix& Matrix::operator=(const Matrix& m) {
       
    Matrix Tmp(m);
    this->swap(Tmp);
      
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& m) {
    for (size_t i = 0;i < _rows;i++)
        for (size_t j = 0;j < _cols;j++)
            _data[i][j] -= m._data[i][j];

    return *this;
}

Matrix& Matrix::operator*=(const Matrix& m) {
    Matrix Ans(_rows, m._cols);

    for (size_t i = 0;i < _rows;i++)
       for (size_t j = 0;j < m._cols;j++)
           for (size_t k = 0;k < _cols;k++) 
             Ans._data[i][j] += _data[i][k] * m._data[k][j];
 
    swap(Ans);   
    return *this;
}

Matrix Matrix::operator+(const Matrix& m) const{
    Matrix M(*this);

    return M += m;
}

Matrix Matrix::operator-(const Matrix& m) const{
    Matrix M(*this);

    return M -= m;
}

Matrix Matrix::operator*(const Matrix& m) const{
    Matrix Tmp(*this);

    return Tmp *= m;
}

