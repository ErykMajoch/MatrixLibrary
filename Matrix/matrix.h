#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>

class Matrix
{
public:
    // Constructors
    Matrix();
    Matrix(unsigned rows, unsigned columns);
    Matrix(unsigned rows, unsigned columns, double initial);

    // Print Matrix
    void Print() const;

private:
    unsigned m_ColumnNumber = 0;
    unsigned m_RowNumber = 0;
    std::vector<std::vector<double>> m_Matrix = {};
};