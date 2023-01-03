#include "Matrix.hpp"

// Matrix source file

namespace ml {

// Constructors
Matrix::Matrix(unsigned rows, unsigned cols): rows_(rows), cols_(cols) 
{
    data_ = new double[rows * cols];
}

Matrix::Matrix(const Matrix& other)
{}


// Destructor
Matrix::~Matrix()
{
    delete[] data_;
}

// Operators
double& Matrix::operator()(unsigned row, unsigned col)
{
    return data_[cols_*row + col];
}
}
