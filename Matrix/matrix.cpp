#include "matrix.h"

// ################
// # Constructors #
// ################ 


// Default Matrix::Matrix constructor
Matrix::Matrix() = default;

// Matrix::Matrix constructor with size parameters
// Initialised all fields to 0.0
Matrix::Matrix(unsigned rows, unsigned columns) {
    m_RowNumber = rows;
    m_ColumnNumber = columns;
    m_Matrix.resize(columns);
    for (unsigned i = 0; i < columns; i++) {
        m_Matrix[i].resize(rows, 0.0);
    }
}

// Matrix::Matrix constructor with size parameters
// Initialised all fields to an initial value
Matrix::Matrix(unsigned rows, unsigned columns, double initial) {
    m_RowNumber = rows;
    m_ColumnNumber = columns;
    m_Matrix.resize(columns);
    for (unsigned i = 0; i < columns; i++) {
        m_Matrix[i].resize(rows, initial);
    }
}

// #####################
// # Access Operations #
// #####################
double& Matrix::operator[](const unsigned &row, const unsigned &column) {
    return this->m_Matrix[column][row];
}



// #############
// # Utilities #
// ############# 

// Prints the fomrated matrix 
void Matrix::Print() const {

    // If matrix is empty, throw an error
    if (m_RowNumber == 0 || m_ColumnNumber == 0) {
        throw std::out_of_range("The matrix is empty!");
    }

    for (std::vector<double> v : m_Matrix) {
        std::cout << "| ";
        for (double d : v) {
            std::cout << d << " ";
        }
        std::cout << "|\n";
    }
}