#include "matrix.hpp"

// matrix source file

namespace ml {

// Constructors
matrix::matrix(int rowsSize, int columnsSize)
{
    this->rowsSize = rowsSize;
    this->columnsSize = columnsSize;
    
    rows = new double* [rowsSize];

    for (int i = 0; i < rowsSize; i++)
        rows[i] = new double[columnsSize];

    for (int i = 0; i < rowsSize; i++)
        for (int j = 0; i < columnsSize; j++)
            rows[i][j] = 0;
}

matrix::matrix(const matrix& other)
{
    this->rows = new double* [other.rowsSize];

    for (int i = 0; i < other.rowsSize; i++)
        this->rows[i] = other.rows[i];
    
    for (int i = 0; i < other.rowsSize; i++)
        for (int j = 0; j < other.columnsSize; j++)
            this->rows[i][j] = other.rows[i][j];
    
}


// Destructor
matrix::~matrix()
{
    
    for (int i = 0; i < columnsSize; i++)
        delete[] rows[i];

    delete[] rows;
}



}
