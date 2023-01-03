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

    double& operator()(unsigned row, unsigned col);
};

}
#endif /* MATRIX_HPP */