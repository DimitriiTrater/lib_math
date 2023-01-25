#ifndef MATRIX_HPP
#define MATRIX_HPP

// matrix header file

namespace ml {
class Matrix
{
private:
    unsigned rows_;
    unsigned cols_;
    double* data_;

public:
    Matrix(unsigned rows, unsigned cols);
    Matrix(const Matrix& other);

    ~Matrix();

    // Matrix& operator = (const Matrix& other);
    double& operator()(unsigned row, unsigned col);
    double  operator()(unsigned row, unsigned col) const;

};

}
#endif /* MATRIX_HPP */