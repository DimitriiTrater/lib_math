#ifndef MATRIX_HPP
#define MATRIX_HPP

// matrix header file

namespace ml {
class matrix
{
private:
    int rowsSize;
    int columnsSize;
    double** rows;
public:
    matrix(int rowsSize, int columnsSize);
    matrix(const matrix& other);


    ~matrix();
};

}
#endif /* MATRIX_HPP */