#include "Matrix.hpp"

// Matrix source file

namespace ml {

// Constructors
Matrix::Matrix(unsigned rows, unsigned cols): rows_(rows), cols_(cols) 
{
    data_ = new double[rows * cols];
}

Matrix::Matrix(const Matrix& other)
{
    this->rows_ = other.rows_;
    this->cols_ = other.cols_;
    this->data_ = new double[other.rows_ * other.cols_];
}


// Destructor
Matrix::~Matrix()
{
    delete[] data_;
}

// Operators

void Matrix::operator = (const Matrix& other){}

double& Matrix::operator()(unsigned row, unsigned col)
{
    return data_[cols_*row + col];
}
}
