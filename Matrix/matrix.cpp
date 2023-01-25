#include "Matrix.hpp"
#include <iostream>

// Matrix source file

namespace ml {

// Constructors
Matrix::Matrix(unsigned rows, unsigned cols)
: rows_(rows), cols_(cols) 
{
    data_ = new double[rows * cols];
}

Matrix::Matrix(const Matrix& other)
{
    this->rows_ = other.rows_;
    this->cols_ = other.cols_;
    this->data_ = new double[other.rows_ * other.cols_];
    for (int i = 0; i < sizeof(data_)/sizeof(data_[0]); i++)
        this->data_[i] = other.data_[i];
}


// Destructor
Matrix::~Matrix()
{
    delete[] data_;
    data_ = nullptr;
}

// Operators

// Matrix& Matrix::operator = (const Matrix& other)
// {
//     if (this == &other)
//         return *this;
//     Matrix result(other.rows, other.cols);
//     this->rows_ = other.rows_;
//     this->cols_ = other.cols_;

// }


double& Matrix::operator()(unsigned row, unsigned col)
{
    if (row >= rows_ || col >= cols_)
        throw "Out of bounds";
    return data_[cols_ * row + col];
}

double Matrix::operator()(unsigned row, unsigned col) const
{
    if (row >= rows_ || col >= cols_)
        throw "Out of bounds";
    return data_[cols_ * row + col];
}


}
