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

double& Matrix::operator[](const unsigned &index) {
    if (m_RowNumber == 1 && m_ColumnNumber > index) {
        return m_Matrix[index][0];
    } else if (m_ColumnNumber == 1 && m_RowNumber > index) {
        return m_Matrix[0][index];
    } else {
        throw std::invalid_argument("Matrix must be unidimentional to access this method");
    }
}

// #####################
// # Scalar Operations #
// #####################

// Normal Operations
Matrix Matrix::operator+(double scalar) {
    if (m_RowNumber == 0 || m_ColumnNumber == 0) {
        throw std::invalid_argument("The matrix is empty");
    }

    Matrix result = Matrix(m_RowNumber, m_ColumnNumber, 0.0);
    for (unsigned i = 0; i < m_ColumnNumber; i++) {
        for (unsigned j = 0; j < m_RowNumber; j++) {
            result[j, i] = m_Matrix[i][j] + scalar;
        }
    }

    return result;
}

Matrix Matrix::operator-(double scalar) {
    if (m_RowNumber == 0 || m_ColumnNumber == 0) {
        throw std::invalid_argument("The matrix is empty");
    }

    Matrix result = Matrix(m_RowNumber, m_ColumnNumber, 0.0);
    for (unsigned i = 0; i < m_ColumnNumber; i++) {
        for (unsigned j = 0; j < m_RowNumber; j++) {
            result[j,i] = this->m_Matrix[i][j] - scalar;
        }
    }

    return result;
}

Matrix Matrix::operator*(double scalar) {
    if (m_RowNumber == 0 || m_ColumnNumber == 0) {
        throw std::invalid_argument("The matrix is empty");
    }

    Matrix result = Matrix(m_RowNumber, m_ColumnNumber, 0.0);
    for (unsigned i = 0; i < m_ColumnNumber; i++) {
        for (unsigned j = 0; j < m_RowNumber; j++) {
            result[j,i] = this->m_Matrix[i][j] * scalar;
        }
    }

    return result;
}

Matrix Matrix::operator/(double scalar) {
    if (m_RowNumber == 0 || m_ColumnNumber == 0) {
        throw std::invalid_argument("The matrix is empty");
    }

    if (scalar == 0) {
        throw std::invalid_argument("Cannot divide matrix by 0");
    }

    Matrix result = Matrix(m_RowNumber, m_ColumnNumber, 0.0);
    for (unsigned i = 0; i < m_ColumnNumber; i++) {
        for (unsigned j = 0; j < m_RowNumber; j++) {
            result[j,i] = this->m_Matrix[i][j] / scalar;
        }
    }

    return result;
}

// Inline Operations
Matrix& Matrix::operator+=(double scalar) {

    if (m_RowNumber == 0 || m_ColumnNumber == 0) {
        throw std::invalid_argument("The matrix is empty");
    }

    for (unsigned i = 0; i < m_ColumnNumber; i++) {
        for (unsigned j = 0; j < m_RowNumber; j++) {
            this->m_Matrix[i][j] = this->m_Matrix[i][j] + scalar;
        }
    }


    return *this;
}

Matrix& Matrix::operator-=(double scalar) {
    if (m_RowNumber == 0 || m_ColumnNumber == 0) {
        throw std::invalid_argument("The matrix is empty");
    }

    for (unsigned i = 0; i < m_ColumnNumber; i++) {
        for (unsigned j = 0; j < m_RowNumber; j++) {
            this->m_Matrix[i][j] = this->m_Matrix[i][j] - scalar;
        }
    }

    return *this;
}

Matrix& Matrix::operator*=(double scalar) {
    if (m_RowNumber == 0 || m_ColumnNumber == 0) {
        throw std::invalid_argument("The matrix is empty");
    }

    for (unsigned i = 0; i < m_ColumnNumber; i++) {
        for (unsigned j = 0; j < m_RowNumber; j++) {
            this->m_Matrix[i][j] = this->m_Matrix[i][j] * scalar;
        }
    }

    return *this;
}

Matrix& Matrix::operator/=(double scalar) {
    if (m_RowNumber == 0 || m_ColumnNumber == 0) {
        throw std::invalid_argument("The matrix is empty");
    }

    if (scalar == 0) {
        throw std::invalid_argument("Cannot divide matrix by 0");
    }

    for (unsigned i = 0; i < m_ColumnNumber; i++) {
        for (unsigned j = 0; j < m_RowNumber; j++) {
            this->m_Matrix[i][j] = this->m_Matrix[i][j] / scalar;
        }
    }

    return *this;
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